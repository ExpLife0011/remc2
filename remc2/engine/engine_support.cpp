#include "engine_support.h"


#ifdef USE_DOSBOX
extern DOS_Device *DOS_CON;
#endif //USE_DOSBOX


void myWriteOut(const char * format, ...) {
	#ifdef USE_DOSBOX
		DEBUG_ShowMsg(format);
	#else
		printf(format);
	#endif //USE_DOSBOX
    
    /*Bit16u sz = 1;
    unsigned char b = 'a';
    DOS_CON->Write(&b, &sz);*/
}

int myprintf(const char * format, ...) {
    char prbuffer[1024];
    va_list arg;
    int done;
    va_start(arg, format);
    done = vsprintf(prbuffer, format, arg);
    va_end(arg);

	#ifdef USE_DOSBOX
		DEBUG_ShowMsg(prbuffer);
	#else
		printf(prbuffer);
	#endif //USE_DOSBOX
    
    //return strlen(prbuffer);
    return done;
    /*Bit16u sz = 1;
    unsigned char b = 'a';
    DOS_CON->Write(&b, &sz);*/
}


//delete after finalization
void pathfix(char* path, char* path2)
{
    if ((path[0] == 'c') || (path[0] == 'C'))
    {
        long len= strlen(path);
        char* fixstring = (char*)"c:/prenos/Magic2/mc2-orig";
        long fixlen = strlen(fixstring);
        for (int i = len;i > 1;i--)
            path2[i + fixlen -2] = path[i];
        for (int i = 0;i < fixlen;i++)
            path2[i] = fixstring[i];
    }
    else
    {
        long len = strlen(path);
        char* fixstring = (char*)"c:/prenos/Magic2/mc2-orig/";
        long fixlen = strlen(fixstring);
        for (int i = len;i > -1;i--)
            path2[i + fixlen] = path[i];
        for (int i = 0;i < fixlen;i++)
            path2[i] = fixstring[i];
    }
}

Bit8u* readbuffer;

char* printbuffer;//char* buffer; // [esp+0h] [ebp-2h]
char* printbuffer2;//char v11; // [esp+40h] [ebp+3Eh]
/*Bit32s x_DWORD_D41A4_x6x = 0;
Bit32s x_DWORD_D41A4_x8x = 0;
Bit32s x_DWORD_D41A4_xAx = -1;
Bit32s x_DWORD_D41A4_xBx = -1;
Bit32s x_DWORD_D41A4_xCx = -1;
Bit32s x_DWORD_D41A4_xDx = -1;
char x_DWORD_D41A4_xB6 = 'C';//2A1644 b6=182
char x_DWORD_D41A4_x16x = '5';//2A15A4 16=22
Bit8u x_DWORD_D41A4_x17x = 0;
Bit8u x_DWORD_D41A4_x18x = 0;
char x_DWORD_D41A4_x19x=0;//2A51BD 19=25
Bit8u x_DWORD_D41A4_x1Ex = 0;
Bit8u x_DWORD_D41A4_x2Bx=0;
Bit8u x_DWORD_D41A4_x2Dx = 0;
Bit32s x_DWORD_D41A4_x33x = 0;
Bit32s x_DWORD_D41A4_x59x = 0;
Bit32s x_DWORD_D41A4_x79x = 0;
Bit32s x_DWORD_D41A4_x7Ax = 0;
Bit32s x_DWORD_D41A4_x7Bx = 0;
Bit32s x_DWORD_D41A4_x7Cx = 0;
Bit32s x_DWORD_D41A4_x7Dx = 0;
Bit32s x_DWORD_D41A4_x7Fx = 0;
//char* char_355198 = "8R5";
Bit32s x_DWORD_D41A4_xB2 = 0;
Bit32s x_DWORD_D41A4_xB4 = 0;
Bit32s x_DWORD_D41A4_xB7 = 0;
Bit32s x_DWORD_D41A4_xBA = 0;
Bit32s x_DWORD_D41A4_xC0 = 0;
Bit32s x_DWORD_D41A4_xCE = 0;
Bit32s x_DWORD_D41A4_xCF = 0;
Bit32s x_DWORD_D41A4_xCD = 0;
Bit32s x_DWORD_D41A4_xD0 = 0;
Bit32s x_DWORD_D41A4_xD8=0;
Bit32s x_DWORD_D41A4_xDC = 0;
Bit32s x_DWORD_D41A4_xE0 = -1;
Bit32s x_DWORD_D41A4_xE1 = -1;
Bit32s x_DWORD_D41A4_xE2=-1;
Bit32s x_DWORD_D41A4_xE6 = -1;
Bit32s x_DWORD_D41A4_xF2 = -1;
Bit32s x_DWORD_D41A4_xF6 = -1;
Bit32s x_DWORD_D41A4_x100 = -1;
Bit32s x_DWORD_D41A4_x235 = -1;
Bit32s x_DWORD_D41A4_x749 = -1;
Bit32s x_DWORD_D41A4_x8CF = -1;
Bit32s x_DWORD_D41A4_x94C = -1;
Bit32s x_DWORD_D41A4_x954 = -1;
Bit32s x_DWORD_D41A4_x21AA = -1;
Bit32s x_DWORD_D41A4_x00 = -1;
Bit32s x_DWORD_D41A4_x9602 = -1;
Bit32s x_DWORD_D41A4_x9603 = -1;
Bit32s x_DWORD_D41A4_x9677 = -1;
Bit32s x_DWORD_D41A4_x967B = -1;
Bit32s x_DWORD_D41A4_x967F = -1;
Bit32s x_DWORD_D41A4_x4 = -1;
Bit32s x_DWORD_D41A4_x965B = -1;
Bit32s x_DWORD_D41A4_x966F = -1;
Bit32s x_DWORD_D41A4_x9683 = -1;
Bit32s x_DWORD_D41A4_x96BF = -1;
Bit32s x_DWORD_D41A4_x9691 = -1;
Bit32s x_DWORD_D41A4_x9692 = -1;*/

//Bit32s x2124_x_DWORD_D41A4_xCx_x_DWORD_D41A0_11234 = 0;

Bit8u *x_DWORD_E9C38_smalltit; // weak

//Bit32s x_DWORD_D41A4 = -1;

int x_DWORD_D41A0 = 0; // weak

Bit32s* x_D41A0_BYTEARRAY_0;
Bit32s* x_D41A0_BYTEARRAY_4;

type_x_D41A0_BYTEARRAY_4_struct x_D41A0_BYTEARRAY_4_struct;

Bit16s x_D41A0_WORDARRAY[10000];

Bit32u x_D41A0_BYTEARRAY_4_0xE6_heapsize;
Bit8u* x_D41A0_BYTEARRAY_4_0xE2_heapbuffer;
//Bit8u* x_D41A0_BYTEARRAY_4_0xDE_heapbuffer;
//Bit32u* off_D918C[0x7c];//turn off - fix it

Bit8u* dword_E9C30[1000]; // weak



Bit8u* x_DWORD_180628b; // weak

void support_begin() {
    readbuffer = (Bit8u*)malloc(1000000);//fix it max 64000
    printbuffer = (char*)malloc(4096);
    //printbuffer[0] = '\0';
    printbuffer2 = (char*)malloc(4096);
	x_DWORD_180628b = (Bit8u*)malloc(320000);

	x_DWORD_E9C38_smalltit= (Bit8u*)malloc(64000);
	//x_D41A0_BYTEARRAY_4_0xDE_heapbuffer= (Bit8u*)malloc(64000);

	/*for (int i = 0;i < 0x1c+0x60;i++)
		off_D918C[i] = new Bit32u;*/
	//2aa18c
	//0 2bc394
	//1
	//2

	dword_E9C30[0] = new Bit8u[4096];
	for (int i = 0;i <4096;i++)
		dword_E9C30[0][0] = 0;
	dword_E9C30[2] = new Bit8u[4096];
	dword_E9C30[4] = new Bit8u[4096];

    //printbuffer2[0] = '\0';
}
void support_end() {
    free(readbuffer);
    free(printbuffer);//char* buffer; // [esp+0h] [ebp-2h]
    free(printbuffer2);//char v11; // [esp+40h] [ebp+3Eh]
	free(x_DWORD_180628b);
	free(x_DWORD_E9C38_smalltit);
	/*for (int i = 0;i < 0x1c;i++)
		free(off_D918C[i]);*/
	//free(x_D41A0_BYTEARRAY_4_0xDE_heapbuffer);
	free(dword_E9C30[0]);
	free(dword_E9C30[2]);
	free(dword_E9C30[4]);
}

void loadfromsnapshot(char* filename, Bit8u* adress, Bit32u adressdos, Bit32u size) {
	char findnamec[500];
	FILE* fptestepc;
	char test[100];
	sprintf(findnamec, "../remc2/memimages/engine-memory-%s", filename);
	fopen_s(&fptestepc, findnamec, "rt");
	fseek(fptestepc, adressdos, SEEK_SET);
	//fread_s(test, size, 1, size, fptestepc);
	fread_s(adress, size, 1, size, fptestepc);
	fclose(fptestepc);
};


void compare_with_snapshot(char* filename, Bit8u* adress, Bit32u adressdos, Bit32u size) {
};
