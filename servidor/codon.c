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

//FUNCIONES
void setInformeADN(char *informe_ADN) {
	//int conta_A_ADN, conta_C_ADN, conta_G_ADN, conta_T_ADN, conta_X_ADN =0; //Cuenta la cantidad de nucleotidos en ADN
	informe_ADN = "A:" + conta_A_ADN + "\n" +
				  "C:" + conta_C_ADN + "\n" +
				  "G:" + conta_G_ADN + "\n" +
				  "T:" + conta_T_ADN + "\n" +
				  "?:" + conta_X_ADN + "\n";
}

void setInformeARN(char *informe_ARN) {
	//int conta_A_ARN, conta_C_ARN, conta_G_ARN, conta_U_ARN, conta_X_ARN =0; //Cuenta la cantidad de nucleotidos en ARN
  informe_ARN = "A:" + conta_A_ARN + "\n" +
          "C:" + conta_C_ARN + "\n" +
          "G:" + conta_G_ARN + "\n" +
          "U:" + conta_U_ARN + "\n" +
          "?:" + conta_X_ARN + "\n";
}

void setInformeAmino(char *informe_Amino) {
	//int conta_Phe,conta_Leu ,conta_Ile ,conta_Met ,conta_Val ,conta_Ser ,conta_Pro ,conta_Thr ,conta_Ala ,conta_Tyr ,conta_Stp ,conta_His ,conta_Gln ,conta_Asn ,conta_Lys ,conta_Asp ,conta_Glu ,conta_Cys ,conta_Trp ,conta_Arg ,conta_Gly, conta_XXX =0 ;
  informe_Amino = "Phe:" + conta_Phe + "\n" +
                  "Leu:" + conta_Leu + "\n" +
                  "Ile:" + conta_Ile + "\n" +
                  "Met:" + conta_Met + "\n" +
                  "Val:" + conta_Val + "\n" +
                  "Ser:" + conta_Ser + "\n" +
                  "Pro:" + conta_Pro + "\n" +
                  "Thr:" + conta_Thr + "\n" +
                  "Ala:" + conta_Ala + "\n" +
                  "Tyr:" + conta_Tyr + "\n" +
                  "Stp:" + conta_Stp + "\n" +
                  "His:" + conta_His + "\n" +
                  "Gln:" + conta_Gln + "\n" +
                  "Asn:" + conta_Asn + "\n" +
                  "Lys:" + conta_Lys + "\n" +
                  "Asp:" + conta_Asp + "\n" +
                  "Glu:" + conta_Glu + "\n" +
                  "Cys:" + conta_Cys + "\n" +
                  "Trp:" + conta_Trp + "\n" +
                  "Arg:" + conta_Arg + "\n" +
                  "?:" + conta_XXX + "\n";
}

int getAminoacido(char *codon){
  if ((strcmp(codon, "UUU")==0)||(strcmp(codon, "UUC")==0)) {
      strcpy(aminoAcido,PHE); //Phenylalanine
      conta_Phe++;
  }

  else if ((strcmp(codon, "UUA")==0)||(strcmp(codon, "UUG")==0)||(strcmp(codon, "CUU")==0)||(strcmp(codon, "CUC")==0)||(strcmp(codon, "CUA")==0)||(strcmp(codon, "CUG")==0)) {
      strcpy(aminoAcido,LEU); //Leucine
      conta_Leu++;
  }
  else if ((strcmp(codon, "AUU")==0)||(strcmp(codon, "AUC")==0)||(strcmp(codon, "AUA")==0)) {
      strcpy(aminoAcido,ILE); //Isoleucine
      conta_Ile++;
  }
  else if (strcmp(codon, "AUG")==0) {
      strcpy(aminoAcido,MET); //Methionine o START
      conta_Met++;
  }
  else if ((strcmp(codon, "GUU")==0)||(strcmp(codon, "GUC")==0)||(strcmp(codon, "GUA")==0)||(strcmp(codon, "GUG")==0)) {
      strcpy(aminoAcido,VAL); //Valine
      conta_Val++;
  }
  else if ((strcmp(codon, "UCU")==0)||(strcmp(codon, "UCC")==0)||(strcmp(codon, "UCA")==0)||(strcmp(codon, "UCG")==0)||(strcmp(codon, "AGU")==0)||(strcmp(codon, "AGC")==0)) {
      strcpy(aminoAcido,SER); //Serine
      conta_Ser++;
  }
  else if ((strcmp(codon, "CCU")==0)||(strcmp(codon, "CCC")==0)||(strcmp(codon, "CCA")==0)||(strcmp(codon, "CCG")==0)) {
      strcpy(aminoAcido,PRO); //Proline
      conta_Pro++;
  }
  else if ((strcmp(codon, "ACU")==0)||(strcmp(codon, "ACC")==0)||(strcmp(codon, "ACA")==0)||(strcmp(codon, "ACG")==0)) {
    	strcpy(aminoAcido,THR); //Threonine
      conta_Thr++;
  }
  else if ((strcmp(codon, "GCU")==0)||(strcmp(codon, "GCC")==0)||(strcmp(codon, "GCA")==0)||(strcmp(codon, "GCG")==0)) {
    	strcpy(aminoAcido,ALA); //Alanina
      conta_Ala++;
  }
  else if ((strcmp(codon, "UAU")==0)||(strcmp(codon, "UAC")==0)) {
    	strcpy(aminoAcido,TYR); //Tyrosine
      conta_Tyr++;
  }
  else if ((strcmp(codon, "UAA")==0)||(strcmp(codon, "UAG")==0)||(strcmp(codon, "UGA")==0)) {
    	strcpy(aminoAcido,STP); //STOP
      conta_Stp++;
  }
  else if ((strcmp(codon, "CAU")==0)||(strcmp(codon, "CAC")==0)) {
    	strcpy(aminoAcido,HIS); //Histidine
      conta_His++;
  }
  else if ((strcmp(codon, "CAA")==0)||(strcmp(codon, "CAG")==0)) {
    	strcpy(aminoAcido,GLN); //Glutamine
      conta_Gln++;
  }
  else if ((strcmp(codon, "AAU")==0)||(strcmp(codon, "AAC")==0)) {
    	strcpy(aminoAcido,ASN); //Asparagine
      conta_Asn++;
  }
  else if ((strcmp(codon, "AAA")==0)||(strcmp(codon, "AAG")==0)) {
    	strcpy(aminoAcido,LYS); //Lysine
      conta_Lys++;
  }
  else if ((strcmp(codon, "GAU")==0)||(strcmp(codon, "GAC")==0)) {
    	strcpy(aminoAcido,ASP); //Aspartic acid
      conta_Asp++;
  }
  else if ((strcmp(codon, "GAA")==0)||(strcmp(codon, "GAG")==0)) {
    	strcpy(aminoAcido,GLU); //Glutamic Acid
      conta_Glu++;
  }
  else if ((strcmp(codon, "UGU")==0)||(strcmp(codon, "UGC")==0)) {
    	strcpy(aminoAcido,CYS); //Cysteine
      conta_Cys++;
  }
  else if ((strcmp(codon, "UGG")==0)) {
    	strcpy(aminoAcido,TRP); //Tryptophan
      conta_Trp++;
  }
  else if ((strcmp(codon, "CGU")==0)||(strcmp(codon, "CGC")==0)||(strcmp(codon, "CGA")==0)||(strcmp(codon, "CGC")==0)||(strcmp(codon, "AGA")==0)||(strcmp(codon, "AGG")==0)) {
    	strcpy(aminoAcido,ARG); //Arginine
      conta_Arg++;
  }
  else if ((strcmp(codon, "GGU")==0)||(strcmp(codon, "GGC")==0)||(strcmp(codon, "GGA")==0)||(strcmp(codon, "GGG")==0)) {
    	strcpy(aminoAcido,GLY); //Glycine
      conta_Gly++;
  }
  else  {
    	strcpy(aminoAcido,UKN);
      conta_XXX++;
  }
}
