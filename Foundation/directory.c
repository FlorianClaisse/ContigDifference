//
// Created by Florian Claisse on 08/01/2023.
//

#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

#include "directory.h"

bool directoryExists(cstring path) {
    DIR *dir = opendir(path);
    if (dir) {
        closedir(dir);
        return true;
    } else if (ENOENT == errno) { return false; }
    ASSERT(0 == 1, "impossible d'ouvrir le dossier")
}

int createDirectory(cstring path) { return mkdir(path, 0700); }

cstring filenameExtension(cstring filename) {
    const char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return "";
    return dot + 1;
}

string fileFullPath(cstring path, cstring filename) {
    ulong pathSize = strlen(path);
    ulong filenameSize = strlen(filename);
    string fullPath;
    if (path[pathSize - 1] == '/') {
        fullPath = malloc(sizeof(char) * (pathSize + filenameSize + 1));
        strcpy(fullPath, path);
        strcat(fullPath, filename);
        return fullPath;
    }

    fullPath = malloc(sizeof(char) * (pathSize + filenameSize + 2));
    strcpy(fullPath, path);
    strcat(fullPath, "/");
    strcat(fullPath, filename);

    return fullPath;
}

StringArray* findFiles(cstring path, cstring extension) {
    DIR *dir = opendir(path);
    ASSERT(dir != NULL, "Impossible d'ouvrir le dossier A.")

    struct dirent *currentFile;
    StringArray *files = SA_init();
    while ( (currentFile = readdir(dir)) != NULL) {
        cstring fileExtension = filenameExtension(currentFile->d_name);
        if (strcmp(fileExtension, extension) == 0) {
            string fullPath = fileFullPath(path, currentFile->d_name);
            SA_add(fullPath, files);
        }
    }

    closedir(dir);
    return files;
}