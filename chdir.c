#include "mylib.h"
char ** chan_dir(WINDOW *win,char ** dir_t,char* path,int * sizedir,int *ptr,int *shift)
{
	char ** dir_o;
	chdir(path);
	chdir(dir_t[*ptr+*shift-1]);
	getcwd(path,100);
	wclear(win);
	box(win,0,0);
	int i =0, j;
	dir = opendir(path);
	struct dirent * entry;
	while ((entry = readdir(dir)) != NULL)
	{
		i++;
	}
	*sizedir = i;
	dir_o = calloc(sizeof(char*),i);
	for (j=0;j<*sizedir;j++)
		dir_o[j] = calloc(sizeof(char),100);
	dir = opendir(path);
	i=0;
	while ((entry = readdir(dir)) != NULL)
	{
		++i;
		if (i<LINES-4){
			mvwprintw(win,i,2,"%s",entry->d_name);
			wrefresh(win);
		}
		sprintf(dir_o[i-1],"%s",entry->d_name);
	}
	*ptr =1;
	*shift = 0;
	wmove(win,1,1);
	wrefresh(win);
	return dir_o;
}
void change_dir(WINDOW *win1,WINDOW * win2)
{
	if (winlock == TRUE)
		dir1 = chan_dir(win1,dir1,path1,&sizedir1,&ptr1,&shift1);
	else if (winlock == FALSE)
		dir2 = chan_dir(win2,dir2,path2,&sizedir2,&ptr2,&shift2);
}