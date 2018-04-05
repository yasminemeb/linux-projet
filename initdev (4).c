#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Parameter can be project type or licence
int twoParams(char *param1, char* param2)
{
	FILE *file;

   	char commande[100];
   	//delete directory if exists 
    system("rm -R Initdev");
    //Create directory
   	sprintf(commande,"mkdir %s",param1);
    system(commande);
    char touchCommand[1000];
    char filepath[100];
    //Creating file, the writing content 
    if(strcmp(param2,"-C")==0)
    {
    	sprintf(touchCommand,"touch %s/main.c %s/LICENCES %s/makefile",param1,param1,param1);
    	system(touchCommand);

    	char code[1000] ;
    	sprintf(code, "#include <stdio.h>\n\nint main()\n{\nprintf (\"Hello world\");\nreturn 0;\n}");
    	sprintf(filepath,"%s/main.c",param1);
    	file = fopen(filepath,"w");
    	fprintf(file, "%s",code);


    }
    else if(strcmp(param2,"-CPP")==0 || strcmp(param2,"-C++")==0)
    {
		sprintf(touchCommand,"touch %s/main.cpp %s/LICENCES %s/makefile",param1, param1,param1);
    	system(touchCommand);

    	char code[1000] ;
    	sprintf(code, "#include <iostream>\nusing namespace std;\nint main()\n{\ncout << \"Hello, World!\";\nreturn 0;\n}");
    	sprintf(filepath,"%s/main.cpp",param1);
    	file = fopen(filepath,"w");
    	fprintf(file, "%s",code);

   	}
    else if(strcmp(param2,"-Py")==0)
    {
    	sprintf(touchCommand,"touch %s/main.py %s/LICENCES %s/makefile",param1,param1,param1);
    	system(touchCommand);

    	char code[1000] ;
    	sprintf(code, "print(\"Hello world\")\n");
    	sprintf(filepath,"%s/main.py",param1);
    	file = fopen(filepath,"w");
    	fprintf(file, "%s",code);

    	
    }
    else if(strcmp(param2,"-Latex")==0)
    {
		sprintf(touchCommand,"touch %s/main.tex %s/LICENCES %s/makefile",param1,param1,param1);
    	system(touchCommand);

    	char code[1000] ;
    	sprintf(code, "\\documentclass[12pt]{article}\n\\usepackage{amsmath}\n\\usepackage{amsfonts}\n\\begin{document}$\n\\mathfrak{H}$ello world!\n\\end{document");
    	sprintf(filepath,"%s/main.tex",param1);
    	file = fopen(filepath,"w");
    	fprintf(file, "%s",code);

    }
    else if(strcmp(param2,"-BEAMER")==0)
    {
    	sprintf(touchCommand,"touch %s/main.bea %s/LICENCES %s/makefile",param1,param1,param1);
    	system(touchCommand);

    	char code[1000] ;
    	sprintf(code, " ");
    	sprintf(filepath,"%s/main.bea",param1);
    	file = fopen(filepath,"w");
    	fprintf(file, "%s",code);    	
    }
    else if(strcmp(param2,"-GPL")==0)
    {
    	sprintf(touchCommand,"touch %s/main.c %s/LICENCES %s/makefile",param1,param1,param1);
    	system(touchCommand);

    	char licenceContent[10000];
    	char licenceCommand[100];
    	sprintf(filepath,"%s/LICENCES",param1);
    	file = fopen(filepath,"w");
		sprintf(licenceContent,"La GPL met en œuvre la notion de copyleft, un jeu de mots anglais faisant référence à la notion de copyright (right en anglais signifie à la fois le droit, c'est-à-dire la règle juridique, et la droite, qui marque une direction) que l'on peut transposer en français en parlant de « Gauche d'auteur » par référence au Droit d'auteur. Pour autant le copyleft n'est pas l'antithèse du copyright, au contraire, puisque le premier s'appuie sur le second. Ainsi le copyleft comme le copyright définissent et encadrent les droits des utilisateurs de façon contraignante. Le mécanisme est identique, mais les objectifs diffèrent : le copyright garantit exclusivement les droits de l'auteur, le copyleft s'attarde tout particulièrement aux droits des utilisateurs, et vise à préserver la liberté d'utiliser, d'étudier, de modifier et de diffuser le logiciel et ses versions dérivées. La GPL est la licence de logiciel libre la plus utilisée. En avril 2004, 74,6 pour cent des 23 479 projets libres listés sur le site Freshmeat — devenu Freecode, en octobre 2011 — et 68,5 pour cent des 52 183 projets libres listés sur SourceForge.net étaient publiés sous licence GPL. Certains contestent cette méthode de mesure en affirmant qu'elle relève du quantitatif (nombre de projets) et ne rend pas compte du qualitatif (utilité des logiciels), mais nul ne conteste depuis longtemps que de nombreux utilisateurs emploient une quantité croissante de logiciels diffusés sous GPL. La GNU GPL a une licence sœur, la LGPL (GNU Lesser General Public License et plus anciennement GNU Library General Public License), une version modifiée pour être moins contraignante quant à son utilisation dans un contexte de cohabitation avec des logiciels propriétaires. Elle a une autre licence sœur, la GFDL (GNU Free Documentation License) qui, elle, est applicable aux manuels, livres ou autres documents écrits. Cette dernière présente toutefois des inconvénients, mis en avant par le projet Debian ; on peut choisir à sa place la GPL, qui est tout à fait applicable à un livre, article de carnet Web ou autre création.");
    	fprintf(file, "%s",licenceContent);	
    }
    else if(strcmp(param2,"-MIT")==0)
    {
    	sprintf(touchCommand,"touch %s/main.c %s/LICENCES %s/makefile",param1,param1,param1);
    	system(touchCommand);

    	char licenceContent[10000];
    	char licenceCommand[100];
    	sprintf(filepath,"%s/LICENCES",param1);
    	file = fopen(filepath,"w");
    	sprintf(licenceContent,"Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the software), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,  and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included  in all copies or substantial portions of the Software. THE SOFTWARE IS PROVIDED , WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.");
       	fprintf(file, "%s",licenceContent);	    	
    }
    else
    {
    	system("echo Uknown arguments, please check the help : initdev –help");
    	return 1;
    }

}
//Two prameters where the parameter has to be only the licence type
int twoParamsBis(char *param1, char* param2)
{
		FILE *file;

   	char commande[100];
    system("rm -R Initdev");
   	sprintf(commande,"mkdir %s",param1);
    system(commande);
    char touchCommand[1000];
    char filepath[100];
   
   sprintf(touchCommand,"touch %s/LICENCES %s/makefile",param1,param1);
   system(touchCommand);

   //Write content of licecne
    if(strcmp(param2,"-GPL")==0)
    {
    	char licenceContent[10000];
    	sprintf(filepath,"%s/LICENCES",param1);
    	file = fopen(filepath,"w");
    	sprintf(licenceContent,"La GPL met en œuvre la notion de copyleft, un jeu de mots anglais faisant référence à la notion de copyright (right en anglais signifie à la fois le droit, c'est-à-dire la règle juridique, et la droite, qui marque une direction) que l'on peut transposer en français en parlant de « Gauche d'auteur » par référence au Droit d'auteur. Pour autant le copyleft n'est pas l'antithèse du copyright, au contraire, puisque le premier s'appuie sur le second. Ainsi le copyleft comme le copyright définissent et encadrent les droits des utilisateurs de façon contraignante. Le mécanisme est identique, mais les objectifs diffèrent : le copyright garantit exclusivement les droits de l'auteur, le copyleft s'attarde tout particulièrement aux droits des utilisateurs, et vise à préserver la liberté d'utiliser, d'étudier, de modifier et de diffuser le logiciel et ses versions dérivées. La GPL est la licence de logiciel libre la plus utilisée. En avril 2004, 74,6 pour cent des 23 479 projets libres listés sur le site Freshmeat — devenu Freecode, en octobre 2011 — et 68,5 pour cent des 52 183 projets libres listés sur SourceForge.net étaient publiés sous licence GPL. Certains contestent cette méthode de mesure en affirmant qu'elle relève du quantitatif (nombre de projets) et ne rend pas compte du qualitatif (utilité des logiciels), mais nul ne conteste depuis longtemps que de nombreux utilisateurs emploient une quantité croissante de logiciels diffusés sous GPL. La GNU GPL a une licence sœur, la LGPL (GNU Lesser General Public License et plus anciennement GNU Library General Public License), une version modifiée pour être moins contraignante quant à son utilisation dans un contexte de cohabitation avec des logiciels propriétaires. Elle a une autre licence sœur, la GFDL (GNU Free Documentation License) qui, elle, est applicable aux manuels, livres ou autres documents écrits. Cette dernière présente toutefois des inconvénients, mis en avant par le projet Debian ; on peut choisir à sa place la GPL, qui est tout à fait applicable à un livre, article de carnet Web ou autre création.");
    	fprintf(file, "%s",licenceContent);
    	
    }
    else if(strcmp(param2,"-MIT")==0)
    {
    	char licenceContent[10000];
    	sprintf(filepath,"%s/LICENCES",param1);
    	file = fopen(filepath,"w");
    	sprintf(licenceContent,"Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the software), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,  and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included  in all copies or substantial portions of the Software. THE SOFTWARE IS PROVIDED , WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.");
       	fprintf(file, "%s",licenceContent);	    	
    }
    else
    {
    	system("echo Uknown arguments, please check the help : initdev –help");
    	return 1;
    }
    return 0;

}

//Two parameters can be type or licence but thrid must be git 
int threeParams(char* param1,char* param2, char* param3)
{
	twoParams(param1, param2);
	if(strcmp(param3,"-git")==0)
	{
		char command[100];
		sprintf(command, "touch %s/.gitignore",param1);
		system(command);
		system("git init");
	}
	else
	{
		printf("Wrong parameter, please check initdev -help");
		return 1;
	}

}

//Licence and project type 
int threeParamsBis(char* param1,char* param2, char* param3)
{
	FILE *file;

   	char commande[100];
    system("rm -R Initdev");
   	sprintf(commande,"mkdir %s",param1);
    system(commande);
    char touchMain[100];
    char filepath[100];

    //Creating licence type and makefiles
	twoParamsBis(param1, param2);
	if(strcmp(param3,"-C")==0)
    {
    	sprintf(touchMain,"touch %s/main.c ",param1);
    	system(touchMain);

    	char code[1000] ;
    	sprintf(code, "#include <stdio.h>\n\nint main()\n{\nprintf (\"Hello world\");\nreturn 0;\n}");
    	sprintf(filepath,"%s/main.c",param1);
    	file = fopen(filepath,"w");
    	fprintf(file, "%s",code);


    }
    else if(strcmp(param3,"-CPP")==0 || strcmp(param2,"-C++")==0)
    {
    	sprintf(touchMain,"touch %s/main.cpp ",param1);
    	system(touchMain);

    	char code[1000] ;
    	sprintf(code, "#include <iostream>\nusing namespace std;\nint main()\n{\ncout << \"Hello, World!\";\nreturn 0;\n}");
    	sprintf(filepath,"%s/main.cpp",param1);
    	file = fopen(filepath,"w");
    	fprintf(file, "%s",code);

   	}
    else if(strcmp(param3,"-Py")==0)
    {

    	sprintf(touchMain,"touch %s/main.py ",param1);
    	system(touchMain);

    	char code[1000] ;
    	sprintf(code, "print(\"Hello world\")\n");
    	sprintf(filepath,"%s/main.py",param1);
    	file = fopen(filepath,"w");
    	fprintf(file, "%s",code);

    	
    }
    else if(strcmp(param3,"-Latex")==0)
    {

    	sprintf(touchMain,"touch %s/main.tex ",param1);
    	system(touchMain);

    	char code[1000] ;
    	sprintf(code, "\\documentclass[12pt]{article}\n\\usepackage{amsmath}\n\\usepackage{amsfonts}\n\\begin{document}$\n\\mathfrak{H}$ello world!\n\\end{document");
    	sprintf(filepath,"%s/main.tex",param1);
    	file = fopen(filepath,"w");
    	fprintf(file, "%s",code);

    }
    else if(strcmp(param3,"-BEAMER")==0)
    {

    	sprintf(touchMain,"touch %s/main.c ",param1);
    	system(touchMain);

    	char code[1000] ;
    	sprintf(code, " ");
    	sprintf(filepath,"%s/main.bea",param1);
    	file = fopen(filepath,"w");
    	fprintf(file, "%s",code);    	
    }
    else
    {
    	system("echo Uknown arguments, please check the help : initdev –help");
    	return 1;
    }
}

int fourParams(char* param1,char* param2, char* param3, char* param4)
{
	//Licence and type project + git
	threeParamsBis(param1,param2,param3);
	if(strcmp(param4,"-git")==0)
	{
		char command[100];
		sprintf(command, "touch %s/.gitignore",param1);
		system(command);
		system("git init");
		
	}
	else
	{
		printf("Wrong parameter, please check initdev -help");
		return 1;
	}
}


int main( int argc, char *argv[] )  {

   if( argc == 2 ) 
   {
	//Project name only
   	if(strcmp(argv[1],"-help")==0)
   	{
   		//getting through the help section
   		system("echo -Name : Afficher le nom de l’application et une petite description\n");
   		system("echo -Syntax : Afficher la syntaxe d’utilisation de la commande initdev ");
   		system("echo -args : Lister les arguments et donner une description de chaque argument.");
   		system("echo -author : Afficher le nom et l’email de l’auteur de l’application.");
   	}
   	else
   	{
   		//Creating directory	
   	char commande[100];

   	sprintf(commande,"mkdir %s",argv[1]);
    system(commande);

    char touchCommande[100];
    sprintf(touchCommande, "touch %s/main.c %s/LICENCES %s/makefile",argv[1],argv[1],argv[1]);
    system(touchCommande);

	}
   }
   else if(argc == 3)
   {
   	//Name and type of project
   	twoParams(argv[1],argv[2]);
   }
   else if(argc == 4)
   {
   	//Name, type and git
   	threeParams(argv[1],argv[2],argv[3]);
   }
   else if(argc == 5)
   {
   	//Name, licence, type, git
   	fourParams(argv[1],argv[2],argv[3],argv[4]);
   }
   else 
   {
      printf("Expected arguments, please check the help : initdev –help.\n");
      return 1;
   }

   //Getting the username
    system("whoami > username.txt");
    char username[1000];
    FILE *unf = fopen("username.txt","r");
    fscanf(unf,"%s\n",username);

    //Creating hiden directory with files 
 
    char mvCommand[1000],rmCommand[100];
    sprintf(mvCommand, "cp -R Initdev /home/%s/.Initdev",username);
    system(mvCommand);
    system("rm username.txt");
    return 0;

}



