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

//CMOCKA includes
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include "cmocka.h"





/******************************* Prototypes ********************************/
int main(){
/** \brief Main function
 *
 * \return int
 *
 */
    printf("Recursive Dir!\n");

    R_Directory *Rdir;
    Rdir=recursivedir2("c:\\temp\\");
    //Rdir=recursivedir2("C:\\dev\\dev_C\\RecursiveDir\\");
    print_Rdir(Rdir);


    return 0;
}

/******************************* Functions ********************************/

