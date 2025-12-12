#include <psyz.h>
#include <libcd.h>
#include <log.h>

#include <inttypes.h>
#include <stdio.h>

#define SECTOR_SIZE 2352

int CdInit(void) {
    NOT_IMPLEMENTED;
    return 0;
}

int CdReading() {
    NOT_IMPLEMENTED;
    return 0;
}

CdlCB CdReadyCallback(CdlCB func) {
    NOT_IMPLEMENTED;
    return func;
}

char* CdSyncModeToStr(int mode) {
    switch (mode) {
    case CdlNop:
        return "CdlNop";
    case CdlSetloc:
        return "CdlSetloc";
    case CdlPlay:
        return "CdlPlay";
    case CdlForward:
        return "CdlForward";
    case CdlBackward:
        return "CdlBackward";
    case CdlReadN:
        return "CdlReadN";
    case CdlSetfilter:
        return "CdlSetfilter";
    case CdlSetmode:
        return "CdlSetmode";
    case CdlGetTD:
        return "CdlGetTD";
    default:
        break;
    }

    return "";
}

#define DECODE_BCD(x) (((x) >> 4) * 10 + ((x) & 0xF))

int CdPosToInt(CdlLOC* p) {
    return (75 * (60 * DECODE_BCD(p->minute) + DECODE_BCD(p->second))) +
           DECODE_BCD(p->sector) - 150;
}

int CdControl(u_char com, u_char* param, u_char* result) {
    NOT_IMPLEMENTED;
    return 0;
}
int CdControlB(u_char com, u_char* param, u_char* result) {
    NOT_IMPLEMENTED;
    return 0;
}

int CdSync(int mode, u_char* result) {
    DEBUGF("mode %0d %s", mode, CdSyncModeToStr(mode));
    NOT_IMPLEMENTED;
    return CdlComplete;
}

int CdMix(CdlATV* vol) {
    NOT_IMPLEMENTED;
    return 0;
}

void ExecCd() { NOT_IMPLEMENTED; }

CdlCB CdSyncCallback(CdlCB func) {
    NOT_IMPLEMENTED;
    return NULL;
}

CdlFILE* CdSearchFile(CdlFILE* fp, char* name) {
    NOT_IMPLEMENTED;
    return NULL;
}

int CdRead(int sectors, u_long* buf, int mode) {
    NOT_IMPLEMENTED;
    return 0;
}

int CdRead2(long mode) {
    NOT_IMPLEMENTED;
    return 0;
}

int CdReadSync(int mode, u_char* result) {
    NOT_IMPLEMENTED;
    return 0;
}

void(*CdDataCallback(void (*func)())) {
    NOT_IMPLEMENTED;
    return func;
}

CdlLOC* CdIntToPos(int i, CdlLOC* p) {
    NOT_IMPLEMENTED;
    return NULL;
}

u_long StGetNext(u_long** addr, u_long** header) {
    NOT_IMPLEMENTED;
    return 0;
}

void StSetRing(u_long* ring_addr, u_long ring_size) { NOT_IMPLEMENTED; }

void StSetStream(u_long mode, u_long start_frame, u_long end_frame,
                 void (*func1)(), void (*func2)()) {
    NOT_IMPLEMENTED;
}

u_long StFreeRing(u_long* base) {
    NOT_IMPLEMENTED;
    return 0;
}
