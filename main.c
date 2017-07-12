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



    return 0;
}

/******************************* Functions ********************************/

