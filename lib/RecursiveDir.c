#include "RecursiveDir.h"

int recursivedir(const char *path){
/** \brief Recursive Dir functionality. Will output all files and directory to the standard output
 *
 * \param *path shall be a valid string pointing to a path such as c:\\temp\\
 * \return 0 is the operation was successfull
 *
 */
    struct dirent *ptrdir;
    DIR *dir;
    dir=opendir(path);

    while( (ptrdir=readdir(dir))!=NULL){
        struct stat stat_buffer;
        char MyStr[250];
        strcpy(MyStr,path) ;
        strcat(MyStr,ptrdir->d_name);
        stat(MyStr, &stat_buffer);

        if ((strcmp(ptrdir->d_name,".")!=0)&&(strcmp(ptrdir->d_name,"..")!=0))
        {
            switch (stat_buffer.st_mode & S_IFMT) {
               case S_IFDIR:
                   printf("%s",MyStr);
                   recursivedir(strcat(MyStr,"\\"))   ;
                   break;
               case S_IFIFO:  printf("%s\n",MyStr);            break;
               case S_IFREG:  printf("%s\n",MyStr);            break;
               break;
               default:       printf("%s  -- unknown?\n",MyStr);                break;
               }
        }

    }

}

int init_Rdir( R_Directory *Rdir){
    /** \brief Initialisation of the struct variable pointer *Rdir
     * \param *Rdir : pointer to a struct R_Directory
     * \return 0 if successful
     *
     */

    Rdir->nb_files=0;
    Rdir->nb_dir=0;
    Rdir->R_Directory=NULL;
    strcpy(Rdir->tfiles,"");
    strcpy(Rdir->cwd,"");

    return 0;
}

int print_Rdir( R_Directory *Rdir){
    printf("Directory %s contains %d files and %d directories\n",Rdir->cwd,Rdir->nb_files,Rdir->nb_dir);
    int nbfiles=Rdir->nb_files;
    while (nbfiles--){
//       printf("%s\n",*(Rdir->tfiles++));
    }

}


R_Directory *recursivedir2( R_Directory *Rdir,char *path){
/** \brief Recursive Dir functionality.
 *
 * \param Rdir
 * \return 0 is the operation was successfull
 *
 */
    struct dirent *ptrdir;
    DIR *dir;

    strcpy(Rdir->cwd,path);
    Rdir->nb_files=0;
    Rdir->nb_dir=0;
    dir=opendir(path);

    while( (ptrdir=readdir(dir))!=NULL){
        struct stat stat_buffer;
        char MyStr[250];
        strcpy(MyStr,path) ;
        strcat(MyStr,ptrdir->d_name);
        stat(MyStr, &stat_buffer);

        if ((strcmp(ptrdir->d_name,".")!=0)&&(strcmp(ptrdir->d_name,"..")!=0)) //management if value is current folder or previous folder
        {
            switch (stat_buffer.st_mode & S_IFMT) {
               case S_IFDIR: //this is a directory: go recursive
                   printf("%s -- DIR\n",MyStr);
                   //recursivedir(strcat(MyStr,"\\"))   ;
                   break;

               case S_IFIFO:  printf("%s\n",MyStr);
                break;

               case S_IFREG: //this is a regular file
                   Rdir->nb_files++;
                   //TODO assignment of the file to the table
                   //Rdir->tfiles=realloc(Rdir->tfiles,Rdir->nb_files*sizeof(Rdir->tfiles[0]));
                   //strcpy(Rdir->tfiles[Rdir->nb_files-1],ptrdir->d_name);
                   printf("%s -- %d\n",ptrdir->d_name,Rdir->nb_files);


               break;

               default:       printf("%s  -- unknown?\n",MyStr);                break;
               }
        }

    }
    //R_Directory *p=malloc(sizeof(R_Directory));
    return Rdir;

}
