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
#include "../lib/RecursiveDir.h"

//CMOCKA includes
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include "cmocka.h"


/* A test case that does nothing and succeeds. */
static void null_test_success(void **state) {
    (void) state; /* unused */
}
static void test1(void **state){
	 assert_string_equal("a","a");
	 (void) state; //unused
}
static void shall_read_dir(void **state){
	R_Directory *Rdir;
    Rdir=recursivedir2("c:\\temp\\");
    print_Rdir(Rdir);
	(void) state; //unused
}
static void shall_fail_reading_non_existant_dir(void **state){
	R_Directory *Rdir;
    Rdir=recursivedir2("c:\\tempi\\");
    print_Rdir(Rdir);
	(void) state; //unused
}
int main(void) {
    const struct CMUnitTest RecursiveDir[] = {
        cmocka_unit_test(null_test_success),
        cmocka_unit_test(test1),
        cmocka_unit_test(shall_read_dir),
        cmocka_unit_test(shall_fail_reading_non_existant_dir)
    };
    return cmocka_run_group_tests(RecursiveDir, NULL, NULL);
    
   printf("	toot\n");
}


