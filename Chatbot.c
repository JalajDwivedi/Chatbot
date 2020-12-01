#include<stdio.h>
#include<string.h>
#include <stdlib.h> 
#include<time.h>
//Coded by Jalaj Dwivedi Under the minor-1 project of 2020. Team Rangers
// Removing spaces
void removeSpaces(char text[128])
{
	char ch = '_';  
      int i;
    //Replace space with specific character ch  
    for(i = 0; i < strlen(text); i++){  
        if(text[i] == ' ')  
            text[i] = ch;  
    }
}
//Random Integer
int printRandoms(int upper,int lower) 
{ 
    int i,num;
    
         num = (rand() % (upper - lower + 1)) + lower;  
     
    return num;
} 
// string matching algorithm
int xposition(char s[128],char t[128])
{
	int l, i, j;
	//finding length of second string
    for (l = 0; t[l] != '\0'; l++);

    for (i = 0, j = 0; s[i] != '\0' && t[j] != '\0'; i++)
    {
        if (s[i] == t[j])
        {
            j++;
        }
        else
        {
            j = 0;
        }
    }

    if (j == l)
    {
        return (i - j + 1);
    }
    else
    {
        return -1;
    }
}  
int main()
{
	int talk=0;
	char mobile[11];
	char email[50];
	char address[100];
	time_t t;   
    time(&t);
    int age;
    char program[50];
	int notunderstood=0;
	char name[30];
	char input[500];
	char input1[20];
	// Keywords(entities)
	char quit[]="Quit";
	char quits[]="quit";
	char info1[]="information";
	char info2[]="Information";
	char info3[]="info";
	char course[]="course";
	char courses[]="courses";
	char coursesB[]="Courses";
	char list[]="List";
	char how[]="How";
	char h[]="H";
	char historyB[]="History";
	char upes[]="UPES";
	char history[]="history";
	char about[]="about";
	char university[]="university";
	char universityB[]="University";
	char thanks[]="Thanks";
	char thank[]="Thank";
	char ciphor[]="Ciphor";
	char help[]="help";
	char fine[]="fine";
	char fineB[]="Fine";
	char dandy[]="Dandy";
	char peachy[]="Peachy";
	char good[]="good";
	char allB[]="All";
	char admission[]="admission";
	char admissionB[]="Admission";
	char what[]="What";
	char procedure[]="procedure";
	char one[]="1";
	char two[]="2";
	char three[]="3";
	char four[]="4";
	char five[]="5";
	char six[]="6";
	char seven[]="7";
	char eight[]="8";
	char nine[]="9";
	char something[]="something";
	char Something[]="Something";
	char documents[]="documents";
	char Document[]="Document";
	char Documents[]="Documents";
	char submit[]="submit";
	char branch[]="branch";
	char know[]="know";
	char programe[]="program";
	char branches[]="branches";
	//Storing conversation in chatbot.txt
	FILE *store=fopen("Chatbot.txt","a");
	fprintf(store,"%s",ctime(&t));
	fprintf(store,"*********************************************************************\n");
	//Conversation begins
	printf(">>Hi my name is Ciphor.\n  I am a chatbot designed to answer your\n  questions and queries regarding UPES admissions\n  and other related info.\n  Once your queries are resolved please enter\n 'quit' to leave conversation.\n");
	printf("  Please enter your name:");
    scanf("%[^\n]%*c",name);
    int namelength=strlen(name);
    fprintf(store,"Name of the user:%s\n",name);
    fprintf(store,"Questions asked by the user:-\n");
	while(talk==0)
	{
		printf(">>");
		scanf("%[^\n]%*c",input);
		fprintf(store,">>%s\n",input);
		removeSpaces(input);
		FILE *file;
		char secret[128];
		int found=0;
	    if(xposition(input,how)!=-1)
		{
			file=fopen("Pleasantries.txt","r"); 
			while (fscanf(file, "%s", secret) != EOF) 
			{
				if (!strcmp(secret, input)) 
				{
        			found = 1;
            		break;
        		}
    		}
    		fclose(file);
    		if(found==1) 
			{
        	int talkoption2=printRandoms(5,1);
				switch(talkoption2)
				{
					case 1:	printf(">>I am good.What about you?\n");
							break;
					case 2: printf(">>I am all well.How are you?\n");
							break;
					case 3: printf(">>All's Well.What about you?\n");
							break;
					case 4: printf(">>I am perfectly fine.How are you?\n");
							break;
					default: printf(">>I am fine.How are you?\n");
				}
    		} 
			else 
			{
        	printf(">>I can't understand.\n  Try rephrasing.\n");
        	notunderstood++;
   		 	}
			
		}
		else if(xposition(input,h)!=-1)
		{
			file=fopen("Hello.txt","r"); 
			while (fscanf(file, "%s", secret) != EOF) 
			{
				if (!strcmp(secret, input)) 
				{
        			found = 1;
            		break;
        		}
    		}
    		fclose(file);
    		if(found==1) 
			{
				int talkoption1=printRandoms(5,1);
				switch(talkoption1)
				{
					case 1:	printf(">>Hi\n");
							break;
					case 2: printf(">>Hello\n");
							break;
					case 3: printf(">>Yo\n");
							break;
					case 4: printf(">>Hlw\n");
							break;
					default: printf(">>Hlo\n");
				}
        	
    		} 
			else 
			{
        	printf(">>I can't understand.\n  Try rephrasing.\n");
        	notunderstood++;
   		 	}
		}
		else if(((xposition(input,something)!=-1 && xposition(input,branch)!=-1)) || xposition(input,programe)!=-1 || xposition(input,branch)!=-1 || xposition(input,course)!=-1 || (xposition(input,something)!=-1 && xposition(input,course)!=-1))
		{
			printf(">>Select one of the schools to learn about the branch:\n");
			printf("  1-School of Computer Science\n   2-School of Engineering\n   3-School of Design\n   4-School of Law\n   5-School of Business\n   6-School of Health Sciences\n   7-School of Modern Media\n");
			
			
			    printf(">>");
				scanf("%[^\n]%*c",input1);
				fprintf(store,">>%s\n",input1);
				removeSpaces(input1);
			if(xposition(input1,one)!=-1)
			{
				        printf(">>Given are all the courses available within that branch:\n");
				        printf("   1-B.Tech in CS with speciallization in Cloud Computing and Virtualization Technology.\n");
				        printf("   Four year program.\n");
						printf("   Presented by IBM.\n");
						printf("   100 seats\n");
						printf("   Emphasize the importance of cloud. And Virtualizations technology.\n");
						
						printf("   2-B.Tech in CS with speciallization in Business Analytics and Optimization.\n");
						printf("   Four year program.\n");
						printf("   Presented by IBM.\n");
						printf("   120 seats\n");
						printf("   Data science, data visualization and power of business intelligence with a touch of Artificial Intelligence.\n");
						
						printf("   3-B.Tech in CS with speciallization in Artificial Intelligence and Machine Learning.\n");
						printf("   Four year program.\n");
						printf("   Presented by IBM.\n");
						printf("   60 seats\n");
						printf("   Artificial Intelligence and Machine Learning techniques and their use in real time.\n");
									
						printf("   4-B.Tech in CS with speciallization in Mainframe Technology.\n");
						printf("   Four year program.\n");
					    printf("   Presented by Xebia.\n");
						printf("   90 seats\n");
						printf("   Bring out the fundamentals of computer. Learn within the computer's world.\n");
									
						printf("   5-B.Tech in CS with speciallization in Cyber Security and Forensics.\n");
						printf("   Four year program.\n");
						printf("   Presented by IBM.\n");
						printf("   120 seats\n");
						printf("   Internet Security, Protection against Cyber Crime.\n");
									
						printf("   6-B.Tech in CS with speciallization in Open Source and Open Standards.\n");
						printf("   Four year program.\n");
						printf("   Presented by IBM.\n");
						printf("   100 seats\n");
						printf("   Everything from computer's fundamentals to protecttion and operating systems.\n");
									
						printf("   7-B.Tech in CS with speciallization in Dev Ops.\n");
						printf("   Four year program.\n");
						printf("   Presented by Xebia.\n");
						printf("   80 seats\n");
						printf("   Dev Operations power.\n");
		   }
		   else if(xposition(input1,two)!=-1)
		   {
			  
				        printf(">>Given are all the courses available within that branch:\n");
						printf("   1-B.Tech in Aerospace Engineering with speciallization in Avinoics.\n");
						printf("   Four year program.\n");
						printf("   100 seats\n");
						printf("   Venture the sky soaring upwards by learning the basic parts and functionalities\n");
									
						printf("   2-B.Tech in Aerospace Engineering.\n");
						printf("   Four year program.\n");
						printf("   120 seats\n");
						printf("   Venture the sky and learn about aerospace.\n");
									
						printf("   3-B.Tech in Petroleum Engineering with speciallization in Upstream.\n");
						printf("   Four year program.\n");
						printf("   120 seats\n");
						printf("   Petroleum engineering basics and special attention to Upstream.\n");
									
						printf("   4-B.Tech in Petroleum Engineering with speciallization in Oil and Gas.\n");
						printf("   Four year program.\n");
						printf("   90 seats\n");
						printf("   Petroleum engineering basics and special attention to oil and gas.\n");
									
						printf("   5-B.Sc Mathematics Hons.\n");
						printf("   Three year program.\n");
						printf("   60 seats\n");
						printf("   Bsc. in mathematics honours.\n");
									
						printf("   6-B.Sc Physics Hons.\n");
						printf("   Three year program.\n");
						printf("   60 seats\n");
						printf("   Bsc. in physics honours.\n");
									
						printf("   7-B.Sc Chemistry Hons.\n");
						printf("   Three year program.\n");
						printf("   60 seats\n");
						printf("   Bsc. in chemistry honours.\n");
									
						
		   }
			else if(xposition(input1,three)!=-1)	
		    {
					    printf(">>Given are all the courses available within that branch:\n");
						printf("   1-B.Des.\n");
						printf("   Three year program.\n");
						printf("   100 seats\n");
						printf("   Venture into the world of design.\n");
									
						printf("   2-M.Des.\n");
						printf("   Four year program.\n");
						printf("   80 seats\n");
						printf("   Master the designing and architecture.\n");
									
		   }
		   else if(xposition(input1,four)!=-1)
		   {
		   
				        printf(">>Given are all the courses available within that branch:\n");
						printf("   1-B.Tech+LLB with specialization in Cyber Crime.\n");
						printf("   2-BA LLB.\n");
						printf("   3-LLB.\n");
						printf("   Please visit the official site for info.\n");
		   }
		   else if(xposition(input1,five)!=-1)
		   {
			            printf(">>Given are all the courses available within that branch:\n");
				        printf("   1-BA Economics Hons. with specialization in Energy Economics.\n");
						printf("   2-BBA.\n");
						printf("   3-B.Com\n");
						printf("   4-MBA.\n");
						printf("   Please visit the official site for info.\n");
		   }
		   else if(xposition(input1,six)!=-1)
		   {
			        	printf(">>Given are all the courses available within that branch:\n");
						printf("   1-B.pharma\n");
						printf("   2-M.pharma\n");
						printf("   Please visit the official site for info.\n");
		   }
		    else if(xposition(input1,seven)!=-1)
			{
			printf(">>Given are all the courses available within that branch:\n");
						printf("   1-BMM\n");
						printf("   Please visit the official site for info.\n");
		    }
		    else
		    {
		    	printf("No information about such school\n");
		    	notunderstood++;
			}
				
				
			
		}
		else if((xposition(input,documents)!=-1 && xposition(input,submit)!=-1) || xposition(input,Document)!=-1 || xposition(input,documents)!=-1)
		{
			file=fopen("DocumentInquiries.txt","r");
			while (fscanf(file, "%s", secret) != EOF)
			{
				if (!strcmp(secret, input)) 
				{
        			found = 1;
            		break;
        		}
			 } 
			 if(found==1)
			 {
			 	    printf(">>The documents you require are:\n");
					printf("  1-Government ID (Aadhar card etc.)\n");
					printf("  2-High school and Inter marksheet\n");
					printf("  3-Migration Certificate\n");
					printf("  4-Domicile Certificate\n");
					printf("  5-Migration Certificate\n");
					printf("  6-Health Certificate( only if you are entering the campus hostel.)\n");
			 }
			 else if((xposition(input,documents)!=-1 && xposition(input,submit)!=-1) || xposition(input,Document)!=-1 || xposition(input,documents)!=-1)
			 {
			 	printf(">>The documents you require are:\n");
					printf("  1-Government ID (Aadhar card etc.)\n");
					printf("  2-High school and Inter marksheet\n");
					printf("  3-Migration Certificate\n");
					printf("  4-Domicile Certificate\n");
					printf("  5-Migration Certificate\n");
					printf("  6-Health Certificate( only if you are entering the campus hostel.)\n");
			 }
			 else
			 {
			  printf(">>I can't understand.\n  Try rephrasing.\n");
        	  notunderstood++; 	
			 }
		}
		else if((xposition(input,courses)!=-1 && xposition(input,info2)!=-1) || (xposition(input,coursesB)!=-1 || xposition(input,info2)!=-1) || (xposition(input,list)!=-1 && xposition(input,courses)!=-1)
		 ||xposition(input,courses)!=-1 ||xposition(input,coursesB)!=-1 || (xposition(input,courses)!=-1 && xposition(input,university)!=-1))
		{
			file=fopen("CourseInquiries.txt","r"); 
			while (fscanf(file, "%s", secret) != EOF) 
			{
				if (!strcmp(secret, input)) 
				{
        			found = 1;
            		break;
        		}
    		}
    		fclose(file);
    		if(found==1) 
			{
				printf(">>The list of courses provided by our University are:\n  1-School of Computer Science\n");
				printf("   ->B.Tech in CS with speciallization in Cloud Computing and Virtualization Technology.\n");
				printf("   ->B.Tech in CS with speciallization in Business Analytics and Optimization.\n");
				printf("   ->B.Tech in CS with speciallization in Artificial Intelligence and Machine Learning.\n");
				printf("   ->B.Tech in CS with speciallization in Mainframe Technology.\n");
				printf("   ->B.Tech in CS with speciallization in Cyber Security and Forensics.\n");
				printf("   ->B.Tech in CS with speciallization in Open Source and Open Standards.\n");
				printf("   ->B.Tech in CS with speciallization in Dev Ops.\n");
				printf("  2-School of Engineering\n");
				printf("   ->B.Tech in Aerospace Engineering with speciallization in Avinoics.\n");
				printf("   ->B.Tech in Aerospace Engineering.\n");
				printf("   ->B.Tech in Petroleum Engineering with speciallization in Upstream.\n");
				printf("   ->B.Tech in Petroleum Engineering with speciallization in Oil and Gas.\n");
				printf("   ->B.Sc Mathematics Hons.\n");
				printf("   ->B.Sc Physics Hons.\n");
				printf("   ->B.Sc Chemistry Hons.\n");
				printf("  3-School of Design\n");
				printf("   ->B.Des.\n");
				printf("  4-School of Law\n");
				printf("   ->B.Tech+LLB with specialization in Cyber Crime.\n");
				printf("  5-School of Business\n");
				printf("   ->BA Economics Hons. with specialization in Energy Economics.\n");
				printf("   ->BBA.\n");
				printf("   ->B.Com\n");
				printf("   ->MBA.\n");
				
				
    		} 
    		else if((xposition(input,courses)!=-1 && xposition(input,info2)!=-1) || (xposition(input,coursesB)!=-1 || xposition(input,info2)!=-1) || (xposition(input,list)!=-1 && xposition(input,courses)!=-1)
		            ||xposition(input,courses)!=-1 ||xposition(input,coursesB)!=-1 || (xposition(input,courses)!=-1 && xposition(input,university)!=-1))
		    {
		    	printf(">>The list of courses provided by our University are:\n  1-School of Computer Science\n");
				printf("   ->B.Tech in CS with speciallization in Cloud Computing and Virtualization Technology.\n");
				printf("   ->B.Tech in CS with speciallization in Business Analytics and Optimization.\n");
				printf("   ->B.Tech in CS with speciallization in Artificial Intelligence and Machine Learning.\n");
				printf("   ->B.Tech in CS with speciallization in Mainframe Technology.\n");
				printf("   ->B.Tech in CS with speciallization in Cyber Security and Forensics.\n");
				printf("   ->B.Tech in CS with speciallization in Open Source and Open Standards.\n");
				printf("   ->B.Tech in CS with speciallization in Dev Ops.\n");
				printf("  2-School of Engineering\n");
				printf("   ->B.Tech in Aerospace Engineering with speciallization in Avinoics.\n");
				printf("   ->B.Tech in Aerospace Engineering.\n");
				printf("   ->B.Tech in Petroleum Engineering with speciallization in Upstream.\n");
				printf("   ->B.Tech in Petroleum Engineering with speciallization in Oil and Gas.\n");
				printf("   ->B.Sc Mathematics Hons.\n");
				printf("   ->B.Sc Physics Hons.\n");
				printf("   ->B.Sc Chemistry Hons.\n");
				printf("  3-School of Design\n");
				printf("   ->B.Des.\n");
				printf("  4-School of Law\n");
				printf("   ->B.Tech+LLB with specialization in Cyber Crime.\n");
				printf("  5-School of Business\n");
				printf("   ->BA Economics Hons. with specialization in Energy Economics.\n");
				printf("   ->BBA.\n");
				printf("   ->B.Com\n");
				printf("   ->MBA.\n");
			}
			else 
			{
        	printf(">>I can't understand.\n  Try rephrasing.\n");
        	notunderstood++;
   		 	}
		}
		
		else if((xposition(input,historyB)!=-1 && xposition(input,upes)!=-1) || xposition(input,upes)!=-1 || xposition(input,university)!=-1 || (xposition(input,about)!=-1 && xposition(input,upes)!=-1) || ((xposition(input,info2)!=-1 && xposition(input,upes)!=-1) && xposition(input,about)!=-1) || (xposition(input,something)!=-1 && xposition(input,upes)!=-1) || (xposition(input,something)!=-1))
		{
			file=fopen("AboutUPES.txt","r"); 
			while (fscanf(file, "%s", secret) != EOF) 
			{
				if (!strcmp(secret, input)) 
				{
        			found = 1;
            		break;
        		}
    		}
    		fclose(file);
    		if(found==1) 
			{
				
				printf(">>The University of Petroleum and Energy Studies (UPES) is a Private university in Dehradun, Uttarakhand, India.\n  It was established in 2003 through the UPES[3] Act, 2003, of the State Legislature of Uttarakhand.\n");
				printf("  The University is sponsored by Hydrocarbon Education Research Society (HERS),\n  which is registered under the ‘Societies Registration Act XXI of 1860’ (Registration No. S-41894 of 2002).\n  UPES is maintained by the University Grants Commission (UGC) under Section 2(f) of the UGC Act, 1956.\n");  
				printf("  It offers undergraduate and postgraduate programs through its eight schools which are:-\n   1-School of Engineering\n   2-School of Computer Science\n   3-School of Design\n   4-School of Law\n   5-School of Business\n   6-School of Health Sciences\n   7-School of Smart Agriculture\n   8-School of Modern Media\n");
				printf("  UPES has collaborated with coursera, enabling its students to have free access to over 3800 global courses.\n");
				printf("  UPES started with an interim campus in Dehradun in August 2003 with 3 courses, 224 students and 15 faculty members.\n  Since then, it has expanded its offerings.\n  Today, UPES has two campuses – one at Bidholi and other at Kandholi – offering more than\n  80 courses (undergraduate, postgraduate and doctoral programs) to approximately 12,000+ students.\n");		
			}
			else if((xposition(input,historyB)!=-1 && xposition(input,upes)!=-1) || xposition(input,upes)!=-1 || xposition(input,university)!=-1 || (xposition(input,about)!=-1 && xposition(input,upes)!=-1) || ((xposition(input,info2)!=-1 && xposition(input,upes)!=-1) && xposition(input,about)!=-1) || (xposition(input,something)!=-1 && xposition(input,upes)!=-1) || (xposition(input,something)!=-1))
			{
			    printf(">>The University of Petroleum and Energy Studies (UPES) is a Private university in Dehradun, Uttarakhand, India.\n  It was established in 2003 through the UPES[3] Act, 2003, of the State Legislature of Uttarakhand.\n");
				printf("  The University is sponsored by Hydrocarbon Education Research Society (HERS),\n  which is registered under the ‘Societies Registration Act XXI of 1860’ (Registration No. S-41894 of 2002).\n  UPES is maintained by the University Grants Commission (UGC) under Section 2(f) of the UGC Act, 1956.\n");  
				printf("  It offers undergraduate and postgraduate programs through its eight schools which are:-\n   1-School of Engineering\n   2-School of Computer Science\n   3-School of Design\n   4-School of Law\n   5-School of Business\n   6-School of Health Sciences\n   7-School of Smart Agriculture\n   8-School of Modern Media\n");
				printf("  UPES has collaborated with coursera, enabling its students to have free access to over 3800 global courses.\n");
				printf("  UPES started with an interim campus in Dehradun in August 2003 with 3 courses, 224 students and 15 faculty members.\n  Since then, it has expanded its offerings.\n  Today, UPES has two campuses – one at Bidholi and other at Kandholi – offering more than\n  80 courses (undergraduate, postgraduate and doctoral programs) to approximately 12,000+ students.\n");		
				
			 } 
			else 
			{
        	printf(">>I can't understand.\n  Try rephrasing.\n");
        	notunderstood++;
   		 	}
		}
		
		else if(xposition(input,thanks)!=-1 || xposition(input,thank)!=-1 || (xposition(input,help)!=-1 && xposition(input,thanks)!=-1) || (xposition(input,ciphor)!=-1 && xposition(input,thanks)!=-1))
		{
			file=fopen("Thankyou.txt","r"); 
			while (fscanf(file, "%s", secret) != EOF) 
			{
				if (!strcmp(secret, input)) 
				{
        			found = 1;
            		break;
        		}
    		}
    		fclose(file);
    		if(found==1) 
			{
				int talkoption3=printRandoms(5,1);
				switch(talkoption3)
				{
					case 1:	printf(">>Your Welcome.\n  Please tell me if you need help with something else.\n");
							break;
					case 2: printf(">>I aim to please.\n  Please let me know if you need help with something else.\n");
							break;
					case 3: printf(">>No problem.\n  Please tell me if you need help with something else.\n");
							break;
					case 4: printf(">>Don't mention it.\n  Please let me know if there's something else I can help with.\n");
							break;
					default: printf(">>Your Welcome.\n  Please tell me if you need help with something else.\n");
				}
        	
    		} 
    	    else 
			{
        	printf(">>I can't understand.\n  Try rephrasing.\n");
        	notunderstood++;
   		 	}
		}
		
		else if(xposition(input,fineB)!=-1 || xposition(input,fine)!=-1 || xposition(input,good)!=-1 || xposition(input,peachy)!=-1 || xposition(input,dandy)!=-1)
		{
			file=fopen("Fine.txt","r"); 
			while (fscanf(file, "%s", secret) != EOF) 
			{
				if (!strcmp(secret, input)) 
				{
        			found = 1;
            		break;
        		}
    		}
    		fclose(file);
    		if(found==1) 
			{
				int talkoption4=printRandoms(3,1);
				switch(talkoption4)
				{
					case 1:	printf(">>Pleased to hear that.\n");
							break;
					case 2: printf(">>Nice to hear that.\n");
							break;
					case 3: printf(">>Nice.\n");
							break;
					default: printf(">>Ok that's good.\n");
				}
        	
    		} 
			else 
			{
        	printf(">>I can't understand.\n  Try rephrasing.\n");
        	notunderstood++;
   		 	}
		}
		
		else if(xposition(input,admission)!=-1 || (xposition(input,admission)!=-1 && xposition(input,what)!=-1) || (xposition(input,admission)!=-1 && xposition(input,procedure)!=-1) || xposition(input,procedure)!=-1 || xposition(input,admissionB)!=-1)
		{
			file=fopen("AdmissionInquiries.txt","r"); 
			while (fscanf(file, "%s", secret) != EOF) 
			{
				if (!strcmp(secret, input)) 
				{
        			found = 1;
            		break;
        		}
    		}
    		fclose(file);
    		if(found==1) 
			{
				printf(">>There are three ways to get admission into UPES:-\n");
				printf("  1-By UPESET (UPES Enterance Test):-\n");
        	    printf("    This exam is MCQ type.And is conducted in the month of may or june.\n");
        	    printf("    This exam contains basic questions from your 11th and 12th standard studies.\n");
        	    printf("    For more details please visit our college website.\n");
        	    printf("  2-By JEE mains score:-\n");
        	    printf("    You need to secure at least 120 marks in mains to qualify.\n");
        	    printf("  3-On the basis of your 12th standard marks.\n");
        	    printf("    You need at least 75% in your 12th standard marks in order to qualify.\n");
				printf("  You can contact the university's enrollment office for more details.\n");
				printf("  Telephone No.-xxxxxxxx\n");
				printf("  Or else check out the official website for more info:-www.upes.ac.in\n");
    		} 
    		else if(xposition(input,admission)!=-1 || (xposition(input,admission)!=-1 && xposition(input,what)!=-1) || (xposition(input,admission)!=-1 && xposition(input,procedure)!=-1) || xposition(input,procedure)!=-1 || xposition(input,admissionB)!=-1)
    		{
    			printf(">>Do you want to ask:\n");
    			printf("  1-The procedure to get admission into UPES?\n");
    			printf("  2-The documents you must carry with you for the registration procedure?\n");
    			printf("  Please select one of the questions by sequence or try to ask the question again.\n");
    			printf(">>");
				scanf("%[^\n]%*c",input1);
				fprintf(store,">>%s\n",input1);
				removeSpaces(input1);
    			if(xposition(input1,one)!=-1)
    			{
    				printf(">>There are three ways to get admission into UPES:-\n");
				    printf("  1-By UPESET (UPES Enterance Test):-\n");
        	        printf("    This exam is MCQ type.And is conducted in the month of may or june.\n");
        	        printf("    This exam contains basic questions from your 11th and 12th standard studies.\n");
        	        printf("    For more details please visit our college website.\n");
        	        printf("  2-By JEE mains score:-\n");
        	        printf("    You need to secure at least 120 marks in mains to qualify.\n");
        	        printf("  3-On the basis of your 12th standard marks.\n");
        	        printf("    You need at least 75% in your 12th standard marks in order to qualify.\n");
				    printf("  You can contact the university's enrollment office for more details.\n");
				    printf("  Telephone No.-xxxxxxxx\n");
				    printf("  Or else check out the official website for more info:-www.upes.ac.in\n");
				}
				else if(xposition(input1,two)!=-1)
				{
					printf(">>The documents you require are:\n");
					printf("  1-Government ID (Aadhar card etc.)\n");
					printf("  2-High school and Inter marksheet\n");
					printf("  3-Migration Certificate\n");
					printf("  4-Domicile Certificate\n");
					printf("  5-Migration Certificate\n");
					printf("  6-Health Certificate( only if you are entering the campus hostel.)\n");
				}
				else
				{
					printf(">>I don't get it.\n   Please ask the question again.\n");
        			notunderstood++;
        		}
			}
			else 
			{
        	printf(">>I can't understand.\n  Try rephrasing.\n");
        	notunderstood++;
   		 	}
		}
		
		
		else if(strcmp(input,quit)==0 || strcmp(input,quits)==0)
		{
			talk=1;
			break;
		}
		else
		{
			printf(">>I can't understand.\n  Try rephrasing.\n");
			notunderstood++;
		}
	}
	//Storing the details in Database.txt
	printf(">>As a protocol I must ask you some questions.\n  If you don't wish to answer them just leave a (-) at the entry level.\n");
	printf(">>Please enter your mobile number.\n");
	printf(">>");
	scanf("%s",mobile);
	int mobilelength=strlen(mobile);
	printf(">>Please enter your email ID.\n");
	printf(">>");
	scanf("%s",email);
	int emaillength=strlen(email);
	printf(">>Please enter your address(city only).\n");
	printf(">>");
	scanf("%s",address);
	int addresslength=strlen(address);
	printf(">>Enter your age.\n");
	printf(">>");
	scanf("%d",&age);
	printf(">>Enter the program you selected. (Example-B.TECH(CSE-CCVT))\n");
	printf(">>");
	scanf("%s",program);
	int programlength=strlen(program);
	FILE *database=fopen("Database.txt","a");
	fprintf(database,"  | %s",name);
	int i;
	for(i=0;i<36-namelength;i++)
	{
		fprintf(database," ");
	}
	fprintf(database,"|  %s",mobile);
	for(i=0;i<20-mobilelength;i++)
	{
		fprintf(database," ");
	}
	fprintf(database,"|  %s",email);
	for(i=0;i<36-emaillength;i++)
	{
		fprintf(database," ");
	}
	fprintf(database,"|  %s",address);
	for(i=0;i<52-addresslength;i++)
	{
		fprintf(database," ");
	}
	fprintf(database,"|   %d",age);
	for(i=0;i<13;i++)
	{
		fprintf(database," ");
	}
	fprintf(database,"|  %s",program);
	for(i=0;i<20-programlength;i++)
	{
		fprintf(database," ");
	}
	fprintf(database,"|  %s",ctime(&t));
	fprintf(database,"  +-------------------------------------+----------------------+--------------------------------------+------------------------------------------------------+------------------+----------------------+--------------------------+\n");
	
	fclose(database);
	//Survey
	printf(">>Do you want to go through a quick survey?\n");
	printf("  1-Yes 2-No\n");
	int choiceSurvey;
	int rate,rate1,rate2;
	printf(">>");
	scanf("%d",&choiceSurvey);
	if(choiceSurvey==1)
	{
		printf(">>How would you rate me?\n");
		printf("  1-Good  2-Average 3-Poor\n");
		printf(">>");
		scanf("%d",&rate);
		fprintf(store,"Rating given by user (1-Good  2-Average 3-Poor):%d\n",rate);
		printf(">>Were all your queries resolved?\n");
		printf("  1-Yes  2-No\n");
		printf(">>");
		scanf("%d",&rate1);
		fprintf(store,"Queries resolved (1-Yes 2-No):%d\n",rate1);
		printf(">>Was I fluent?\n");
		printf("  1-Yes  2-No\n");
		printf(">>");
		scanf("%d",&rate2);
		fprintf(store,"Fluency (1-Yes 2-No):%d\n",rate2);
	}
	else
	{
		printf(">>Ok no problem. Another time.\n");
	}
	//Exit
	printf(">>You are now exiting the conversation.\n");
	printf("  On behalf of UPES, I bid you farewell!\n");
	int talkoption=printRandoms(5,1);
	switch(talkoption)
	{
	case 1:     printf("  Thank you!!\n");
				break;
	case 2:		printf("  Nice talking to you today!!\n");
				break;
	case 3:		printf("  Have a pleasant day!!\n");
				break;
	case 4:     printf("  Have a good day!!\n");
				break;
	default:    printf("  Have a nice day!!\n");
	}
	fprintf(store,"The number of questions which Ciphor failed to understand:%d\n",notunderstood);
	fprintf(store,"*********************************************************************\n");
	fclose(store);
}

