/****************************************************************************
 * Copyright (C) 2017 by Ludovic DEPARIS                                    *
 *                                                                          *
 *                                                                          *
 *   You should have received a copy of the GNU Lesser General Public       *
 *   License along with Box.  If not, see <http://www.gnu.org/licenses/>.   *
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <strings.h>
#define MAX_PATH_LENGTH 256

/******************************* Prototypes ********************************/
struct R_Directory{
    int nb_files;/**< nb of files stored in the table tfiles */
    int nb_dir;/**< nb of directory stored in the table tdir */
    char cwd[MAX_PATH_LENGTH];
    char *tfiles[1][MAX_PATH_LENGTH];
    char *R_Directory;
} ;

int recursivedir(const char *path);
int init_Rdir(struct R_Directory *Rdir);
int print_Rdir(struct R_Directory *Rdir);
void AddElement(char **table, char *mot);

/******************************* Prototypes ********************************/
int main(){
/** \brief Main function
 *
 * \return int
 *
 */
    printf("Hello world!\n");
    //recursivedir("c:\\temp\\");
    struct R_Directory Rdir;
    printf("%d\n",sizeof(Rdir));
    init_Rdir(&Rdir);
    strcpy(Rdir.cwd,"c:\\temp\\");
    recursivedir2(&Rdir);
    print_Rdir(&Rdir);


    char **tstrings; //equivalent de *tstrings[]
    int n_elt=0;
    int n=0;
    tstrings=malloc(n_elt*sizeof(char *));

    tstrings[0]=NULL;
    printf("********\n");
    tstrings[0]=malloc(sizeof(char[MAX_PATH_LENGTH]));
    strcpy(tstrings[0],"toto");
    n_elt++;
    n=n_elt;
    while(n--){
        printf("%s\n",tstrings[n]);
    }

    printf("********\n");
    tstrings[n_elt]=malloc(sizeof(char[MAX_PATH_LENGTH]));
    strcpy(tstrings[n_elt],"titi");
    printf("taille de tstrings: %d\n", sizeof(tstrings));

    n_elt++;
    n=n_elt;
    while(n--){
        printf("%s\n",tstrings[n]);
    }

printf("********\n");
    tstrings[n_elt]=realloc(tstrings,sizeof(char[MAX_PATH_LENGTH]));
    strcpy(tstrings[n_elt],"tata");
    printf("taille de tstrings: %d\n", sizeof(tstrings));

    n_elt++;
    n=n_elt;
    while(n--){
        printf("%s\n",tstrings[n]);
    }



    /*char *s[MAX_PATH_LENGTH];
    strcpy(s,"toto");
    tstrings = (char **) realloc(tstrings, (sarray_len + 1) * sizeof(char *));
    sarray_len+=1;
    printf("taille de tstrings: %d, nb mots:%d\n", sizeof(tstrings),sarray_len);
    strcpy(tstrings[0],"toto");
    tstrings = (char **) realloc(tstrings, (sarray_len + 1) * sizeof(char *));
    sarray_len+=1;
    printf("taille de tstrings: %d, nb mots:%d\n", sizeof(tstrings),sarray_len);
*/

    return 0;
}

/******************************* Functions ********************************/
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

int init_Rdir(struct R_Directory *Rdir){
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

int print_Rdir(struct R_Directory *Rdir){
    printf("Directory %s contains %d files and %d directories\n",Rdir->cwd,Rdir->nb_files,Rdir->nb_dir);
    int nbfiles=Rdir->nb_files;
    while (nbfiles--){
//        printf("%s\n",(Rdir->tfiles++));
    }

}

int recursivedir2(struct R_Directory *Rdir){
/** \brief Recursive Dir functionality.
 *
 * \param Rdir
 * \return 0 is the operation was successfull
 *
 */
    struct dirent *ptrdir;
    DIR *dir;
    char *path[MAX_PATH_LENGTH];
    strcpy(path,Rdir->cwd);
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
                   printf("%s -- DIR\n",MyStr);
                   //recursivedir(strcat(MyStr,"\\"))   ;
                   break;
               case S_IFIFO:  printf("%s\n",MyStr);            break;
               case S_IFREG:
                   Rdir->nb_files++;
                   realloc(Rdir->tfiles,Rdir->nb_files*sizeof(Rdir->tfiles[0]));
                   printf("%d\n",sizeof(Rdir->tfiles[0]));
                   printf("%s-%d\n",MyStr,Rdir->nb_files);

               break;
               break;
               default:       printf("%s  -- unknown?\n",MyStr);                break;
               }
        }

    }
    return 0;

}

