//
// Created by Florian Claisse on 08/01/2023.
//

#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>

#include "Directory.h"

bool directoryExists(cstring path) {
    DIR *dir = opendir(path);
    if (dir) {
        closedir(dir);
        return true;
    } else if (ENOENT == errno) { return false; }
    ASSERT(0 == 1, "impossible d'ouvrir le dossier")
}

int createDirectory(cstring path) { return mkdir(path, 0700); }