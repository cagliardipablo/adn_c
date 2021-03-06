/****************************************************************************/
/*                                                                        	*/
/*	adn_c - Aplicación Cliente/Servidor para traducir cadenas de ADN.	      */
/*                                                                        	*/
/*			Internetworking - 2015                                   		        */
/*                                                                        	*/
/*       	UTN  | Universidad Tecnologica Nacional                           */
/*       	FRLP | Facultad Regional La Plata                                 */
/*             	   Buenos Aires, Argentina                                  */
/*                                                                        	*/
/*       	> Cagliardi, Pablo Esteban    <cagliardipablo@yahoo.com.ar>       */
/*                                                                        	*/
/****************************************************************************/

//INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//VARIABLES
int conta_Phe,conta_Leu ,conta_Ile ,conta_Met ,conta_Val ,conta_Ser ,conta_Pro ,conta_Thr ,conta_Ala ,conta_Tyr ,conta_Stp ,conta_His ,conta_Gln ,conta_Asn ,conta_Lys ,conta_Asp ,conta_Glu ,conta_Cys ,conta_Trp ,conta_Arg ,conta_Gly,conta_XXX ;
char codon[3];
char aminoAcido[3]="???";

//CONSTANTS
const char PHE [3] ="Phe";
const char LEU [3] ="Leu";
const char ILE [3] ="Ile";
const char MET [3] ="Met";
const char VAL [3] ="Val";
const char SER [3] ="Ser";
const char PRO [3] ="Pro";
const char THR [3] ="Thr";
const char ALA [3] ="Ala";
const char TYR [3] ="Tyr";
const char STP [3] ="Stp";
const char HIS [3] ="His";
const char GLN [3] ="Gln";
const char ASN [3] ="Asn";
const char LYS [3] ="Lys";
const char ASP [3] ="Asp";
const char GLU [3] ="Glu";
const char CYS [3] ="Cys";
const char TRP [3] ="Trp";
const char ARG [3] ="Arg";
const char GLY [3] ="Gly";
const char UKN [3] ="???";

//HEADERS
void setInformeADN(char *informe_ADN);
void setInformeARN(char *informe_ARN);
void setInformeAmino(char *informe_Amino);
void getAminoacido(char codon, char* amino3, int buffersize);
