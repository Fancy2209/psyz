#include <psyz.h>
#include <log.h>
#include <string.h>
#include <kernel.h>

void _adjust_path(char* dst, const char* src, int maxlen) {
    INFOF("TODO: adjust path '%s'", src);
    strncpy(dst, src, maxlen);
    dst[maxlen - 1] = '\0';
}

struct DIRENTRY* my_firstfile(char* dirPath, struct DIRENTRY* firstEntry) {
    NOT_IMPLEMENTED;
    return NULL;
}

struct DIRENTRY* my_nextfile(struct DIRENTRY* outEntry) {
    NOT_IMPLEMENTED;
    return NULL;
}

long my_erase(char* path) {
    char adjPath[0x100];
    _adjust_path(adjPath, path, sizeof(adjPath));

    DEBUGF("remove('%s')", adjPath);
    return remove(adjPath) == 0;
}

long my_format(char* fs) {
    NOT_IMPLEMENTED;
    return 0;
}

#include <direct.h>
int my_open(const char* devname, int flag) {
    // only map the known flags and discard the rest
    int oflag = (int)flag & (O_WRONLY | O_RDWR | O_NONBLOCK | O_CREAT);
    char path[0x100];
    _adjust_path(path, devname, sizeof(path));
    if (oflag & O_CREAT) {
        return _creat(path, 0644);
    } else {
        struct stat st;
        if (_stat(path, &st) != 0) {
            WARNF("path '%s' mapped from '%s' not found", path, devname);
            return -1;
        }
        if (!(st.st_mode & S_IFREG)) {
            if (st.st_mode & S_IFDIR) {
                WARNF(
                    "path '%s' mapped from '%s' is a directory", path, devname);
            } else {
                WARNF("path '%s' mapped from '%s' is not a regular file", path,
                      devname);
            }
            return -1;
        }
        return _open(path, oflag);
    }
}
int my_close(int fd) { return (long)_close((int)fd); }
long my_lseek(long fd, long offset, long flag) {
    return _lseek((int)fd, (off_t)offset, (int)flag);
}
long my_read(long fd, void* buf, long n) {
    return (long)_read((int)fd, buf, (size_t)n);
}
long my_write(long fd, void* buf, long n) {
    return (long)_write((int)fd, buf, (size_t)n);
}
long my_ioctl(long fd, long com, long arg) { 
    NOT_IMPLEMENTED;
    return 0; 
}
