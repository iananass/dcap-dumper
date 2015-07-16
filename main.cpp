#include "Dumper.h"
#include <iostream>
#include <unistd.h>

static const unsigned char SomePacket[60] = {
    0xe8, 0x94, 0xf6, 0x3f, 0x98, 0x05, 0x00, 0x1e, /* ...?.... */
    0x67, 0x64, 0x78, 0x91, 0x08, 0x06, 0x00, 0x01, /* gdx..... */
    0x08, 0x00, 0x06, 0x04, 0x00, 0x02, 0x00, 0x1e, /* ........ */
    0x67, 0x64, 0x78, 0x91, 0xc0, 0xa8, 0x00, 0x15, /* gdx..... */
    0xe8, 0x94, 0xf6, 0x3f, 0x98, 0x05, 0xc0, 0xa8, /* ...?.... */
    0x00, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
    0x00, 0x00, 0x00, 0x00 /* .... */
};

int main ( int argc, char **argv )
{
    Dumper dmp1;
    if (!dmp1.Open("dmp1.cap")) {
        std::cerr << "Can not open dmp1.cap\n";
        return 1;
    }
    
    Dumper dmp2("dmp2.cap");
    if (!dmp2.IsOpened()) {
        std::cerr << "Can not open dmp2.cap\n";
        return 1;
    }
    
    dmp1.DumpPacket(SomePacket, sizeof(SomePacket));
    dmp2.DumpPacket(SomePacket, sizeof(SomePacket));
    dmp1.Flush();
    
    
    sleep(60);
    
    return 0;
}