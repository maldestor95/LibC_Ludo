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
    return 0;
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
    strcpy(*(Rdir->tfiles),"\0");
    strcpy(Rdir->cwd,"\0");

    return 0;
}

int print_Rdir( R_Directory *Rdir){
    printf("Directory %s contains %d files and %d directories\n",Rdir->cwd,Rdir->nb_files,Rdir->nb_dir);
    int nbfiles=Rdir->nb_files;
    int nbdir=Rdir->nb_dir;
    while (nbfiles--){
       //printf("%s\n",*(Rdir->tfiles++));
    }
    while (nbdir--){
        //print_Rdir(Rdir->R_Directory[nbdir]);
    }
    return 0;
}


R_Directory *recursivedir2(char *path){
/** \brief Recursive Dir functionality.
 *
 * \param input is a char *
 * \return R_directory structure filled in.
 *
 */
    struct dirent *ptrdir;
    DIR *dir;
    static nbcall =0;
    nbcall ++;

    R_Directory *Rdir;

    //Initialisation of Rdir
    Rdir=malloc(sizeof(R_Directory));
    strcpy(Rdir->cwd,path);
    Rdir->nb_files=0;
    Rdir->nb_dir=0;
    Rdir->tfiles=malloc(sizeof(char *));
    Rdir->tfiles=NULL;
    Rdir->R_Directory=malloc(sizeof(R_Directory *));
    Rdir->R_Directory=NULL;

    R_Directory *newdir;
    char newfolder[MAX_PATH_LENGTH];

    //analysis of the directory
    dir=opendir(path);
    printf("%d nb call, PATH: %s\n", nbcall, path);

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
                   strcpy(newfolder,Rdir->cwd);
                   strcat(newfolder,ptrdir->d_name);
                   strcat(newfolder,"\\");
                   Rdir->nb_dir++;
                   Rdir->R_Directory=realloc(Rdir->R_Directory,Rdir->nb_dir*sizeof(R_Directory *));
                   Rdir->R_Directory[Rdir->nb_dir-1]=recursivedir2(newfolder);
                   break;

               case S_IFIFO:  printf("%s\n",MyStr);
                break;

               case S_IFREG: //this is a regular file
                    Rdir->tfiles = realloc( Rdir->tfiles , (Rdir->nb_files+1)*sizeof(char *)); // addition of a new char in memory
                    Rdir->tfiles[Rdir->nb_files]=malloc(MAX_PATH_LENGTH*sizeof(char));
                    strcpy(Rdir->tfiles[Rdir->nb_files],ptrdir->d_name);
                    Rdir->nb_files++;
                    break;
               default:       printf("%s  -- unknown?\n",MyStr);                break;
               }
        }
    }
    return (R_Directory * )Rdir;
}
