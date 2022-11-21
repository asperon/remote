#include <stdio.h>
#include <windows.h>
#include "remote.h"
#include "../lsapi/lsapi.h"

const char szAppName[] = "Remote"; 
messageType *messages = NULL;
int nummessages = 0;

void BangSend(HWND caller ,char* args);

int initModule(HWND ParentWnd, HINSTANCE dllInst, wharfDataType* wd)
{
	return initModuleEx (ParentWnd, dllInst, wd->lsPath);
}

int initModuleEx(HWND ParentWnd, HINSTANCE dllInst, LPCSTR szPath)
{
	FILE *f = LCOpen(NULL);

	if (f)
	{
		char	buffer[4096];
		char	token1[4096], token2[4096], token3[4096], token4[4096], extra_text[4096];
		char*	tokens[4];
		
		tokens[0] = token1;
		tokens[1] = token2;
		tokens[2] = token3;
		tokens[3] = token4;

		buffer[0] = 0;

		while (LCReadNextConfig (f, "*Send", buffer, sizeof (buffer)))
		{
			int count;

			token1[0] = token2[0] = token3[0] = token4[0] = extra_text[0] = '\0';

			count = LCTokenize (buffer, tokens, 4, extra_text);
			
			if (!messages)
				messages = (messageType *)malloc(sizeof(messageType));
			else
				messages = realloc(messages, (nummessages+1)*sizeof(messageType));
			strcpy(messages[nummessages].szName, token2);
			strcpy(messages[nummessages].szWindow, token3);
			strcpy(messages[nummessages].szMessage, token4);
			strcpy(messages[nummessages].szParameters, extra_text);
			nummessages++;

		}
		LCClose(f);
		AddBangCommand("!SEND", BangSend);
	}
	return 0;
}

void quitModule(HINSTANCE dllInst)
{
	if (messages != NULL) free(messages);
	RemoveBangCommand("!SEND");	
}

void BangSend (HWND caller,char* args)
{
	int num=-1,i;

	HWND hwndApp;
	
	if ((int)strlen(args) == 0) return;

	for (i=0;i<(int)strlen(args);i++)
		if(!isalpha(args[i]))
			args[i]=0;
	for (i = 0; i < nummessages; i++)
	{
		if (!strcmpi(messages[i].szName, args))
		{
			num = i;
			break;
		}
	}

	if (num == -1) return;
	if (hwndApp = FindWindow(messages[num].szWindow, NULL))
	{
		SendMessage(hwndApp, WM_COMMAND,atoi(messages[num].szMessage),0);
	}
	else
	{
		if (messages[num].szParameters != '\0') {
			ShellExecute(caller, "open", messages[num].szParameters ,NULL, NULL, SW_MINIMIZE);
		}
	}

}