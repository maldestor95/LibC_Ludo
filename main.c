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
#include "lib/RecursiveDir.h"





/******************************* Prototypes ********************************/
int main(){
/** \brief Main function
 *
 * \return int
 *
 */
    printf("Recursive Dir!\n");

    //  Normal Recursive dir on C:\\temp
    //recursivedir("c:\\temp\\");


    // Recursive dir with the structure
    R_Directory Rdir;
    //init_Rdir(&Rdir);
    //strcpy(Rdir.cwd,"c:\\temp\\");
    recursivedir2(&Rdir,"c:\\temp\\");
    print_Rdir(&Rdir);


//*****************************
/*    char **t_mot;
    size_t n_mot;

    printf("combien d'elements:");
    n_mot=5;//scanf("%d",&n_el);
    t_mot=malloc(n_mot*sizeof(char *));
    for (int i=0;i<n_mot;i++)
    {
        t_mot[i]=malloc(80*sizeof(char));
        strcpy(t_mot[i],"a\0");
        printf("%d -- %s\n",i,t_mot[i]);
    }

    n_mot=10;//scanf("%d",&n_el);
    *t_mot=realloc(t_mot,n_mot*sizeof(char *));
    for (int i=5;i<n_mot;i++)
    {
        t_mot[i]=malloc(80*sizeof(char));
        strcpy(t_mot[i],"b\0");
        printf("%d -- %s\n",i,t_mot[i]);
    }


*/

    return 0;
}

/******************************* Functions ********************************/

