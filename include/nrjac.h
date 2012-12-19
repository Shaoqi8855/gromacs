/*
 * This file is part of the GROMACS molecular simulation package.
 *
 * Copyright (c) 1991-2000, University of Groningen, The Netherlands.
 * Copyright (c) 2001-2004, The GROMACS development team,
 * check out http://www.gromacs.org for more information.
 * Copyright (c) 2012, by the GROMACS development team, led by
 * David van der Spoel, Berk Hess, Erik Lindahl, and including many
 * others, as listed in the AUTHORS file in the top-level source
 * directory and at http://www.gromacs.org.
 *
 * GROMACS is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1
 * of the License, or (at your option) any later version.
 *
 * GROMACS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with GROMACS; if not, see
 * http://www.gnu.org/licenses, or write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA.
 *
 * If you want to redistribute modifications to GROMACS, please
 * consider that scientific software is very special. Version
 * control is crucial - bugs must be traceable. We will be happy to
 * consider code for inclusion in the official distribution, but
 * derived work must not be called official GROMACS. Details are found
 * in the README & COPYING files - if they are missing, get the
 * official version at http://www.gromacs.org.
 *
 * To help us fund GROMACS development, we humbly ask that you cite
 * the research papers on the package. Check out http://www.gromacs.org.
 */

#ifndef _nrjac_h
#define _nrjac_h
#include "visibility.h"
#include "typedefs.h"

#ifdef __cplusplus
extern "C" {
#endif

GMX_LIBGMX_EXPORT
void jacobi(double **a,int n,double d[],double **v,int *nrot);
/* 
 * real   **omega = input matrix a[0..n-1][0..n-1] must be symmetric
 * int     natoms = number of rows and columns
 * real      NULL = d[0]..d[n-1] are the eigenvalues of a[][]
 * real       **v = v[0..n-1][0..n-1] the eigenvectors:
 *                                    v[i][j] is component i of vector j
 * int      *irot = number of jacobi rotations
 */

GMX_LIBGMX_EXPORT
int m_inv_gen(real **m,int n,real **minv);
/* Produces minv, a generalized inverse of m.
 * Inversion is done via diagonalization,
 * eigenvalues smaller than 1e-6 times the average diagonal element
 * are assumed to be zero.
 * For zero eigenvalues 1/eigenvalue is set to zero for the inverse matrix.
 * Returns the number of zero eigenvalues.
 */

#ifdef __cplusplus
}
#endif

#endif