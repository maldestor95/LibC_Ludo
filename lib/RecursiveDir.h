/****************************************************************************
 * Copyright (C) 2017 by Ludovic DEPARIS                                    *
 * Recursive Directory Library                                                                         *
 *                                                                          *
 *   You should have received a copy of the GNU Lesser General Public       *
 *   License along with Box.  If not, see <http://www.gnu.org/licenses/>.   *
 ****************************************************************************/
/**< doxydoc on recursiveDir */
#ifndef RECURSIVEDIR_H_INCLUDED
    #define RECURSIVEDIR_H_INCLUDED
    #include <stdio.h>
    #include <stdlib.h>
    #include <dirent.h>
    #include <sys/stat.h>
    #include <strings.h>

    #define MAX_PATH_LENGTH 10000
    /******************************* Prototypes ********************************/
    typedef struct {
        int nb_files;/**< nb of files stored in the table tfiles */
        int nb_dir;/**< nb of directory stored in the table tdir */
        char cwd[MAX_PATH_LENGTH];
        char **tfiles;
        void **R_Directory;
    } R_Directory;
    /******************************* Function **********************************/
    int recursivedir(const char *path);
    R_Directory *recursivedir2( char *path);
    int init_Rdir( R_Directory *Rdir);
    int print_Rdir( R_Directory *Rdir);
    void AddElement(char **table, char *mot);

#endif // RECURSIVEDIR_H_INCLUDED
