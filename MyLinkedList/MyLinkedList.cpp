// MyLinkedList.cpp : Defines the entry point for the console application.
// 

// Header files required
#include "stdafx.h"

// Create the main menu and its submenus here
int main(size_t argc, char **argv)
{
	char confirm, **argv_std = (char **)malloc(sizeof(char *) * argc);
	// Create a corresponding string array from argv to reach alignment to the parameters the user enters
	for (size_t i = 0; i < argc; i++)
	{
		*(argv_std + i) = (char *)malloc(sizeof(char) * (strlen(*(argv + i)) + 1));
		Alignment(*(argv_std + i), *(argv + i));
	}
	// Go to Help interface if the user enters "MyLinkList.exe"
	if (argc == 1)
	{
		printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
		printf_s("MyLinkList.exe {Main_menu_command} {Submenu_command}\n\n");
		printf_s("DESCRIPTION:\n\n");
		printf_s("\tStudent Management Application (SMA) works by inquiring, modifying\n");
		printf_s("\tor deleting students' information. \n\n");
		printf_s("MAIN MENU COMMANDS:\n\n");
		printf_s("\t%-20s\t- Input function.\n", "/Input");
		printf_s("\t%-20s\t- Query information.\n", "/Inquire");
		printf_s("\t%-20s\t- Changes to the student information.\n", "/Modify");
		printf_s("\t%-20s\t- Delete student information.\n", "/Delete");
		printf_s("\nFor more information about these main menu commands, specify an");
		printf_s("\noption immediately before /?.\n\n");
		printf_s("\tExamples:\n");
		printf_s("\t\tMyLinkList.exe /Input /?\n");
		printf_s("\t\tMyLinkList.exe /Inquire /?\n");
		printf_s("\t\tMyLinkList.exe /Modify /?\n");
		printf_s("\t\tMyLinkList.exe /Delete /?\n\n\n");
	}
	// Checking if "/?" exists
	else if (argc == 2)
	{
		// Go to Help interface if the user enters "MyLinkList.exe /?"
		if (strcmp(*(argv_std + 1), "/?") == 0)
		{
			printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
			printf_s("MyLinkList.exe {Main_menu_command} {Submenu_command}\n\n");
			printf_s("DESCRIPTION:\n\n");
			printf_s("\tStudent Management Application (SMA) works by inquiring, modifying\n");
			printf_s("\tor deleting students' information. \n\n");
			printf_s("MAIN MENU COMMANDS:\n\n");
			printf_s("\t%-20s\t- Input function.\n", "/Input");
			printf_s("\t%-20s\t- Query information.\n", "/Inquire");
			printf_s("\t%-20s\t- Changes to the student information.\n", "/Modify");
			printf_s("\t%-20s\t- Delete student information.\n", "/Delete");
			printf_s("\nFor more information about these main menu commands, specify an");
			printf_s("\noption immediately before /?.\n\n");
			printf_s("\tExamples:\n");
			printf_s("\t\tMyLinkList.exe /Input /?\n");
			printf_s("\t\tMyLinkList.exe /Inquire /?\n");
			printf_s("\t\tMyLinkList.exe /Modify /?\n");
			printf_s("\t\tMyLinkList.exe /Delete /?\n\n\n");
		}
		// The program exits if "/?" doesn't exist
		else
		{
			printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
			printf_s("Error: 87\n\n");
			printf_s("The parameter is incorrect.\n");
			exit(ERROR_ILLEGAL_PARAMETERS);
		}
	}
	// Switch to the main menu and its corresponding submenus if illegal parameters don't exist
	else if (argc == 3)
	{
		// Switch to the main menu "/Input"
		if (strcmp(*(argv_std + 1), "/Input") == 0)
		{
			// Switch to the sub help interface if the user enters "MyLinkList.exe /Input /?"
			if (strcmp(*(argv_std + 2), "/?") == 0)
			{
				printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
				printf_s("/Input {Submenu_command}\n\n");
				printf_s("\tInput function.\n\n");
				printf_s("\t%-20s\t- Enter student information.\n", "/Input /Student");
				printf_s("\t%-20s\t- Enter course information.\n", "/Input /Class_s");
				printf_s("\t%-20s\t- Enter student achievement information.\n", "/Input /Grade_s");
				printf_s("\t\tExamples:\n");
				printf_s("\t\t\tMyLinkList.exe /Input /Class_s\n\n\n");
			}
			// Checking which submenu command the user enters
			else if (strcmp(*(argv_std + 2), "/Student") == 0 || strcmp(*(argv_std + 2), "/Class_s") == 0 || strcmp(*(argv_std + 2), "/Grade_s") == 0)
			{
				printf_s("\nThis will input function, ready to continue?(Y/N)");
				confirm = getchar();
				getchar();
				// Create a new link list and assign values pending confirmation
				if (confirm == 'Y' || confirm == 'y')
				{
					node *phead, *ptail, *pnew;
					pnew = (node *)malloc(sizeof(node));
					// Memory allocation for sub categories
					{
						pnew->sinfo = (student *)malloc(sizeof(student));
						pnew->cinfo = (class_s *)malloc(sizeof(class_s));
						pnew->ginfo = (grade_s *)malloc(sizeof(grade_s));
					}
					printf_s("\nThe operation completed successfully.\n");
					phead = ptail = pnew;
					pnew->back = pnew->next = pnew;
					printf_s("\nAdd new?(Y/N)");
					confirm = getchar();
					getchar();
					// Add new nodes to the link list pending confirmation
					if (confirm == 'Y' || confirm == 'y')
					{
						// Add new nodes until the user discards
						while (true)
						{
							pnew = (node *)malloc(sizeof(node));
							{
								pnew->sinfo = (student *)malloc(sizeof(student));
								pnew->cinfo = (class_s *)malloc(sizeof(class_s));
								pnew->ginfo = (grade_s *)malloc(sizeof(grade_s));
							}
							printf_s("\nThe operation completed successfully.\n");
							ptail->next = pnew;
							pnew->back = ptail;
							ptail = pnew;
							ptail->next = phead;
							phead->back = ptail;
							printf_s("\nAdd new?(Y/N)");
							confirm = getchar();
							getchar();
							// Stop from adding new nodes if the user discards
							if (confirm != 'Y' && confirm != 'y')
							{
								break;
							}
						}
					}
					ptail->next = phead;
					phead->back = ptail;
					printf_s("\nDo you want to use default values for students?");
					printf_s("\nEnter 'Y' to use default or 'N' to assign values to them by yourself.(Y/N)");
					confirm = getchar();
					getchar();
					// Switch to the corresponding submenu
					if (strcmp(*(argv_std + 2), "/Student") == 0)
					{
						InputStudent(phead, confirm);
					}
					else if (strcmp(*(argv_std + 2), "/Class_s") == 0)
					{
						InputClass_s(phead, confirm);
					}
					else if (strcmp(*(argv_std + 2), "/Grade_s") == 0)
					{
						InputGrade_s(phead, confirm);
					}
					FreeAll(phead);
				}
			}
			// The program exits if the corresponding submenu command doesn't exist
			else
			{
				printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
				printf_s("Error: 87\n\n");
				printf_s("The parameter is incorrect.\n");
				exit(ERROR_ILLEGAL_PARAMETERS);
			}
		}
		// Switch to the main menu "/Inquire"
		else if (strcmp(*(argv_std + 1), "/Inquire") == 0)
		{
			// Switch to the sub help interface if the user enters "MyLinkList.exe /Inquire /?"
			if (strcmp(*(argv_std + 2), "/?") == 0)
			{
				printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
				printf_s("/Inquire {Submenu_command}\n\n");
				printf_s("\tQuery information.\n\n");
				printf_s("\t%-20s\t- Query the number of students.\n", "/Inquire /Number");
				printf_s("\t%-20s\t- Query of grade in an elective course.\n", "/Inquire /Grade_s");
				printf_s("\t%-20s\t- Statistics the number of minority students.\n", "/Inquire /Minority");
				printf_s("\t%-20s\t- Statistics list a course exam students.\n", "/Inquire /Fail");
				printf_s("\t\tExamples:\n");
				printf_s("\t\t\tMyLinkList.exe /Inquire /Grade\n\n\n");
			}
			else if (strcmp(*(argv_std + 2), "/Number") == 0 || strcmp(*(argv_std + 2), "/Grade_s") == 0 || strcmp(*(argv_std + 2), "/Minority") == 0 || strcmp(*(argv_std + 2), "/Fail") == 0)
			{
				printf_s("\nThis will query information, ready to continue?(Y/N)");
				confirm = getchar();
				getchar();
				// Create a new link list and assign values from binary files pending confirmation
				if (confirm == 'Y' || confirm == 'y')
				{
					FILE *fps, *fpc, *fpg;
					// If opening files in the read mode successfully
					if (fopen_s(&fps, ".\\sinfo.bin", "r") == NULL && fopen_s(&fpc, ".\\cinfo.bin", "r") == NULL && fopen_s(&fpg, ".\\ginfo.bin", "r") == NULL)
					{
						node *phead, *ptail, *pnew;
						pnew = (node *)malloc(sizeof(node));
						{
							pnew->sinfo = (student *)malloc(sizeof(student));
							pnew->cinfo = (class_s *)malloc(sizeof(class_s));
							pnew->ginfo = (grade_s *)malloc(sizeof(grade_s));
						}
						phead = ptail = pnew;
						fread_s(pnew->sinfo, sizeof(student), sizeof(student), 1, fps);
						fread_s(pnew->cinfo, sizeof(class_s), sizeof(class_s), 1, fpc);
						fread_s(pnew->ginfo, sizeof(grade_s), sizeof(grade_s), 1, fpg);
						pnew->back = pnew->next = pnew;
						// Add new nodes until the binary readers reach the end of the files
						while (true)
						{
							pnew = (node *)malloc(sizeof(node));
							{
								pnew->sinfo = (student *)malloc(sizeof(student));
								pnew->cinfo = (class_s *)malloc(sizeof(class_s));
								pnew->ginfo = (grade_s *)malloc(sizeof(grade_s));
							}
							fread_s(pnew->sinfo, sizeof(student), sizeof(student), 1, fps);
							fread_s(pnew->cinfo, sizeof(class_s), sizeof(class_s), 1, fpc);
							fread_s(pnew->ginfo, sizeof(grade_s), sizeof(grade_s), 1, fpg);
							ptail->next = pnew;
							pnew->back = ptail;
							ptail = pnew;
							ptail->next = phead;
							phead->back = ptail;
							// Stop from adding new nodes if the binary readers reach the end of the files
							if (feof(fps) == 1 && feof(fpc) == 1 && feof(fpg) == 1)
							{
								ptail->back->next = ptail->next;
								ptail->next->back = ptail->back;
								ptail = ptail->back;
								{
									free(pnew->sinfo);
									free(pnew->cinfo);
									free(pnew->ginfo);
								}
								free(pnew);
								break;
							}
						}
						ptail->next = phead;
						phead->back = ptail;
						if (strcmp(*(argv_std + 2), "/Number") == 0)
						{
							printf_s("\n<student number>%zd\n", InquireNumber(phead));
						}
						else if (strcmp(*(argv_std + 2), "/Grade_s") == 0)
						{
							int sno, cno;
							printf_s("\n<student number>");
							scanf_s("%d", &sno);
							getchar();
							printf_s("\n<class_s number>");
							scanf_s("%d", &cno);
							getchar();
							printf_s("\n<grade>%.1lf\n", InquireGrade_s(phead, sno, cno));
						}
						else if (strcmp(*(argv_std + 2), "/Minority") == 0)
						{
							int *number, *pnumber;
							node *Mphead, *Mptail, *Mpnew, *Mpoint, *point = phead;
							Mpnew = (node *)malloc(sizeof(node));
							{
								Mpnew->sinfo = (student *)malloc(sizeof(student));
								Mpnew->cinfo = (class_s *)malloc(sizeof(class_s));
								Mpnew->ginfo = (grade_s *)malloc(sizeof(grade_s));
							}
							Mphead = Mptail = Mpnew;
							strcpy_s(Mpnew->sinfo->nation, _STRING_DEFAULT);
							Mpnew->back = Mpnew->next = Mpnew;
							point = point->next;
							// Add new nodes to the "nation" category with the same number of students until reaching the tail
							// if not reaching the tail
							if (point->next != phead && point->next != NULL)
							{
								while (true)
								{
									Mpnew = (node *)malloc(sizeof(node));
									{
										Mpnew->sinfo = (student *)malloc(sizeof(student));
										Mpnew->cinfo = (class_s *)malloc(sizeof(class_s));
										Mpnew->ginfo = (grade_s *)malloc(sizeof(grade_s));
									}
									strcpy_s(Mpnew->sinfo->nation, _STRING_DEFAULT);
									Mptail->next = Mpnew;
									Mpnew->back = Mptail;
									Mptail = Mpnew;
									Mptail->next = Mphead;
									Mphead->back = Mptail;
									// Stop from adding new nodes if reaching the tail
									if (point->next == phead || point->next == NULL)
									{
										break;
									}
									point = point->next;
								}
							}
							Mptail->next = Mphead;
							Mphead->back = Mptail;
							number = (int *)malloc(sizeof(int) * InquireNumber(Mphead));
							// The numbers of minorities are initialized as 0
							for (size_t j = 0; j < InquireNumber(Mphead); j++)
							{
								*(number + j) = 0;
							}
							InquireMinority(phead, Mphead, number);
							pnumber = number;
							Mpoint = Mphead;
							// Output the numbers of minorities in the "nation" category until exceeded
							while (true)
							{
								printf_s("\n<nation>%s, <number>%d;\n", Mpoint->sinfo->nation, *pnumber);
								pnumber++;
								// Stop from outputting the numbers of minorities in the "nation" category if exceeded
								if (strcmp(Mpoint->next->sinfo->nation, _STRING_DEFAULT) == 0)
								{
									break;
								}
								Mpoint = Mpoint->next;
							}
						}
						else if (strcmp(*(argv_std + 2), "/Fail") == 0)
						{
							int *sno, *psno, cno;
							node *point;
							sno = (int *)malloc(sizeof(int) * InquireNumber(phead));
							// Student numbers are initialized as -1
							for (size_t j = 0; j < InquireNumber(phead); j++)
							{
								*(sno + j) = EOF;
							}
							printf_s("\n<class_s number>");
							scanf_s("%d", &cno);
							getchar();
							sno = InquireFail(phead, sno, cno);
							psno = sno;
							// Output the namelist in which student numbers are available in the black list until exceeded
							while (true)
							{
								point = phead;
								// Checking if student numbers are available in the black list until reaching the tail
								while (true)
								{
									// Output the corresponding student information if the student number is available
									if (point->sinfo->sno == *psno)
									{
										printf_s("\n<student number>%d, <student name>%s, <sex>%c, <age>%d, <nation>%s;\n", point->sinfo->sno, point->sinfo->sname, point->sinfo->sex, point->sinfo->age, point->sinfo->nation);
									}
									// Check complete if reaching the tail
									if (point->next == phead || point->next == NULL)
									{
										break;
									}
									point = point->next;
								}
								// Stop from outputting the namelist if exceeded
								if (*(psno + 1) == EOF)
								{
									break;
								}
								psno++;
							}
						}
						FreeAll(phead);
						fclose(fps);
						fclose(fpc);
						fclose(fpg);
					}
				}
			}
			else
			{
				printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
				printf_s("Error: 87\n\n");
				printf_s("The parameter is incorrect.\n");
				exit(ERROR_ILLEGAL_PARAMETERS);
			}
		}
		// Switch to the main menu "/Modify"
		else if (strcmp(*(argv_std + 1), "/Modify") == 0)
		{
			// Switch to the sub help interface if the user enters "MyLinkList.exe /Modify /?"
			if (strcmp(*(argv_std + 2), "/?") == 0)
			{
				printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
				printf_s("/Modify {Submenu_command}\n\n");
				printf_s("\tChanges to the student information.\n\n");
				printf_s("\t%-20s\t- Modify the student course information.\n", "/Modify /Grade_s");
				printf_s("\t\tExamples:\n");
				printf_s("\t\t\tMyLinkList.exe /Modify /Grade_s\n\n\n");
			}
			else if (strcmp(*(argv_std + 2), "/Grade_s") == 0)
			{
				printf_s("\nThis will changes to the student information, ready to continue?(Y/N)");
				confirm = getchar();
				getchar();
				// Create a new link list and assign values from binary files pending confirmation
				if (confirm == 'Y' || confirm == 'y')
				{
					FILE *fps, *fpc, *fpg;
					// If opening files in the read mode successfully
					if (fopen_s(&fps, ".\\sinfo.bin", "r") == NULL && fopen_s(&fpc, ".\\cinfo.bin", "r") == NULL && fopen_s(&fpg, ".\\ginfo.bin", "r") == NULL)
					{
						node *phead, *ptail, *pnew;
						pnew = (node *)malloc(sizeof(node));
						{
							pnew->sinfo = (student *)malloc(sizeof(student));
							pnew->cinfo = (class_s *)malloc(sizeof(class_s));
							pnew->ginfo = (grade_s *)malloc(sizeof(grade_s));
						}
						phead = ptail = pnew;
						fread_s(pnew->sinfo, sizeof(student), sizeof(student), 1, fps);
						fread_s(pnew->cinfo, sizeof(class_s), sizeof(class_s), 1, fpc);
						fread_s(pnew->ginfo, sizeof(grade_s), sizeof(grade_s), 1, fpg);
						pnew->back = pnew->next = pnew;
						while (true)
						{
							pnew = (node *)malloc(sizeof(node));
							{
								pnew->sinfo = (student *)malloc(sizeof(student));
								pnew->cinfo = (class_s *)malloc(sizeof(class_s));
								pnew->ginfo = (grade_s *)malloc(sizeof(grade_s));
							}
							fread_s(pnew->sinfo, sizeof(student), sizeof(student), 1, fps);
							fread_s(pnew->cinfo, sizeof(class_s), sizeof(class_s), 1, fpc);
							fread_s(pnew->ginfo, sizeof(grade_s), sizeof(grade_s), 1, fpg);
							ptail->next = pnew;
							pnew->back = ptail;
							ptail = pnew;
							ptail->next = phead;
							phead->back = ptail;
							if (feof(fps) == 1 && feof(fpc) == 1 && feof(fpg) == 1)
							{
								ptail->back->next = ptail->next;
								ptail->next->back = ptail->back;
								ptail = ptail->back;
								{
									free(pnew->sinfo);
									free(pnew->cinfo);
									free(pnew->ginfo);
								}
								free(pnew);
								break;
							}
						}
						ptail->next = phead;
						phead->back = ptail;
						int sno, cno;
						double grade;
						printf_s("\n<student number>");
						scanf_s("%d", &sno);
						getchar();
						printf_s("\n<class_s number>");
						scanf_s("%d", &cno);
						getchar();
						printf_s("\n<grade>");
						scanf_s("%lf", &grade);
						getchar();
						ModifyGrade_s(phead, sno, cno, grade);
						node *point = phead;
						// Output grade_s information until reaching the tail
						while (true)
						{
							printf_s("\n<student number>%d, <class number>%d, <grade>%.1lf;\n", point->ginfo->sno, point->ginfo->cno, point->ginfo->grade);
							// Stop from outputting grade_s information if reaching the tail
							if (point->next == phead || point->next == NULL)
							{
								break;
							}
							point = point->next;
						}
						FreeAll(phead);
						fclose(fps);
						fclose(fpc);
						fclose(fpg);
					}
				}
			}
			else
			{
				printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
				printf_s("Error: 87\n\n");
				printf_s("The parameter is incorrect.\n");
				exit(ERROR_ILLEGAL_PARAMETERS);
			}
		}
		// Switch to the main menu "/Delete"
		else if (strcmp(*(argv_std + 1), "/Delete") == 0)
		{
			// Switch to the sub help interface if the user enters "MyLinkList.exe /Delete /?"
			if (strcmp(*(argv_std + 2), "/?") == 0)
			{
				printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
				printf_s("/Delete {Submenu_command}\n\n");
				printf_s("\tDelete student information.\n\n");
				printf_s("\t%-20s\t- Delete all the information a student.\n", "/Delete /Student");
				printf_s("\t%-20s\t- Delete student course information.\n", "/Delete /Class_s");
				printf_s("\t\tExamples:\n");
				printf_s("\t\t\tMyLinkList.exe /Delete /Class_s\n\n\n");
			}
			else if (strcmp(*(argv_std + 2), "/Student") == 0 || strcmp(*(argv_std + 2), "/Class_s") == 0)
			{
				printf_s("\nThis will delete student information., ready to continue?(Y/N)");
				confirm = getchar();
				getchar();
				// Create a new link list and assign values from binary files pending confirmation
				if (confirm == 'Y' || confirm == 'y')
				{
					FILE *fps, *fpc, *fpg;
					// If opening files in the read mode successfully
					if (fopen_s(&fps, ".\\sinfo.bin", "r") == NULL && fopen_s(&fpc, ".\\cinfo.bin", "r") == NULL && fopen_s(&fpg, ".\\ginfo.bin", "r") == NULL)
					{
						node *phead, *ptail, *pnew;
						pnew = (node *)malloc(sizeof(node));
						{
							pnew->sinfo = (student *)malloc(sizeof(student));
							pnew->cinfo = (class_s *)malloc(sizeof(class_s));
							pnew->ginfo = (grade_s *)malloc(sizeof(grade_s));
						}
						phead = ptail = pnew;
						fread_s(pnew->sinfo, sizeof(student), sizeof(student), 1, fps);
						fread_s(pnew->cinfo, sizeof(class_s), sizeof(class_s), 1, fpc);
						fread_s(pnew->ginfo, sizeof(grade_s), sizeof(grade_s), 1, fpg);
						pnew->back = pnew->next = pnew;
						while (true)
						{
							pnew = (node *)malloc(sizeof(node));
							{
								pnew->sinfo = (student *)malloc(sizeof(student));
								pnew->cinfo = (class_s *)malloc(sizeof(class_s));
								pnew->ginfo = (grade_s *)malloc(sizeof(grade_s));
							}
							fread_s(pnew->sinfo, sizeof(student), sizeof(student), 1, fps);
							fread_s(pnew->cinfo, sizeof(class_s), sizeof(class_s), 1, fpc);
							fread_s(pnew->ginfo, sizeof(grade_s), sizeof(grade_s), 1, fpg);
							ptail->next = pnew;
							pnew->back = ptail;
							ptail = pnew;
							ptail->next = phead;
							phead->back = ptail;
							if (feof(fps) == 1 && feof(fpc) == 1 && feof(fpg) == 1)
							{
								ptail->back->next = ptail->next;
								ptail->next->back = ptail->back;
								ptail = ptail->back;
								{
									free(pnew->sinfo);
									free(pnew->cinfo);
									free(pnew->ginfo);
								}
								free(pnew);
								break;
							}
						}
						ptail->next = phead;
						phead->back = ptail;
						if (strcmp(*(argv_std + 2), "/Student") == 0)
						{
							int sno;
							printf_s("\n<student number>");
							scanf_s("%d", &sno);
							getchar();
							DeleteStudent(phead, ptail, sno);
							printf_s("\nStudent information\n");
							node *point = phead;
							// Output student information until reaching the tail
							while (true)
							{
								printf_s("\n<student number>%d, <student name>%s, <sex>%c, <age>%d, <nation>%s;\n", point->sinfo->sno, point->sinfo->sname, point->sinfo->sex, point->sinfo->age, point->sinfo->nation);
								// Stop from outputting student information if reaching the tail
								if (point->next == phead || point->next == NULL)
								{
									break;
								}
								point = point->next;
							}
							printf_s("\nGrade_s information\n");
							point = phead;
							// Output grade_s information until reaching the tail
							while (true)
							{
								printf_s("\n<student number>%d, <class number>%d, <grade>%.1lf;\n", point->ginfo->sno, point->ginfo->cno, point->ginfo->grade);
								// Stop from outputting grade_s information if reaching the tail
								if (point->next == phead || point->next == NULL)
								{
									break;
								}
								point = point->next;
							}
						}
						else if (strcmp(*(argv_std + 2), "/Class_s") == 0)
						{
							int cno;
							printf_s("\n<class_s number>");
							scanf_s("%d", &cno);
							getchar();
							DeleteClass_s(phead, ptail, cno);
							printf_s("\nClass_s information\n");
							node *point = phead;
							// Output class_s information until reaching the tail
							while (true)
							{
								printf_s("\n<class_s number>%d, <class_s name>%s, <credit>%.1lf;\n", point->cinfo->cno, point->cinfo->cname, point->cinfo->credit);
								// Stop from outputting class_s information if reaching the tail
								if (point->next == phead || point->next == NULL)
								{
									break;
								}
								point = point->next;
							}
							printf_s("\nGrade_s information\n");
							point = phead;
							// Output grade_s information until reaching the tail
							while (true)
							{
								printf_s("\n<student number>%d, <class number>%d, <grade>%.1lf;\n", point->ginfo->sno, point->ginfo->cno, point->ginfo->grade);
								// Stop from outputting grade_s information if reaching the tail
								if (point->next == phead || point->next == NULL)
								{
									break;
								}
								point = point->next;
							}
						}
						FreeAll(phead);
						fclose(fps);
						fclose(fpc);
						fclose(fpg);
					}
				}
			}
			else
			{
				printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
				printf_s("Error: 87\n\n");
				printf_s("The parameter is incorrect.\n");
				exit(ERROR_ILLEGAL_PARAMETERS);
			}
		}
		// The program exits if the main menu command doesn't exist
		else
		{
			printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
			printf_s("Error: 87\n\n");
			printf_s("The parameter is incorrect.\n");
			exit(ERROR_ILLEGAL_PARAMETERS);
		}
	}
	// Switch to the help interfaces of submenu commands
	else if (argc == 4)
	{
		if (strcmp(*(argv_std + 1), "/Input") == 0)
		{
			if (strcmp(*(argv_std + 2), "/Student") == 0)
			{
				if (strcmp(*(argv_std + 3), "/?") == 0)
				{
					printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
					printf_s("/Input /Student\n\n");
					printf_s("\tEnter student information.\n\n\n");
				}
				else
				{
					printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
					printf_s("Error: 87\n\n");
					printf_s("The parameter is incorrect.\n");
					exit(ERROR_ILLEGAL_PARAMETERS);
				}
			}
			else if (strcmp(*(argv_std + 2), "/Class_s") == 0)
			{
				if (strcmp(*(argv_std + 3), "/?") == 0)
				{
					printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
					printf_s("/Input /Class_s\n\n");
					printf_s("\tEnter course information.\n\n\n");
				}
				else
				{
					printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
					printf_s("Error: 87\n\n");
					printf_s("The parameter is incorrect.\n");
					exit(ERROR_ILLEGAL_PARAMETERS);
				}
			}
			else if (strcmp(*(argv_std + 2), "/Grade_s") == 0)
			{
				if (strcmp(*(argv_std + 3), "/?") == 0)
				{
					printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
					printf_s("/Input /Grade_s\n\n");
					printf_s("\tEnter student achievement information.\n\n\n");
				}
				else
				{
					printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
					printf_s("Error: 87\n\n");
					printf_s("The parameter is incorrect.\n");
					exit(ERROR_ILLEGAL_PARAMETERS);
				}
			}
			else
			{
				printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
				printf_s("Error: 87\n\n");
				printf_s("The parameter is incorrect.\n");
				exit(ERROR_ILLEGAL_PARAMETERS);
			}
		}
		else if (strcmp(*(argv_std + 1), "/Inquire") == 0)
		{
			if (strcmp(*(argv_std + 2), "/Number") == 0)
			{
				if (strcmp(*(argv_std + 3), "/?") == 0)
				{
					printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
					printf_s("/Inquire /Number\n\n");
					printf_s("\tQuery the number of students.\n\n\n");
				}
				else
				{
					printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
					printf_s("Error: 87\n\n");
					printf_s("The parameter is incorrect.\n");
					exit(ERROR_ILLEGAL_PARAMETERS);
				}
			}
			else if (strcmp(*(argv_std + 2), "/Grade_s") == 0)
			{
				if (strcmp(*(argv_std + 3), "/?") == 0)
				{
					printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
					printf_s("/Inquire /Grade_s\n\n");
					printf_s("\tQuery of grade in an elective course.\n\n\n");
				}
				else
				{
					printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
					printf_s("Error: 87\n\n");
					printf_s("The parameter is incorrect.\n");
					exit(ERROR_ILLEGAL_PARAMETERS);
				}
			}
			else if (strcmp(*(argv_std + 2), "/Minority") == 0)
			{
				if (strcmp(*(argv_std + 3), "/?") == 0)
				{
					printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
					printf_s("/Inquire /Minority\n\n");
					printf_s("\tStatistics the number of minority students.\n\n\n");
				}
				else
				{
					printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
					printf_s("Error: 87\n\n");
					printf_s("The parameter is incorrect.\n");
					exit(ERROR_ILLEGAL_PARAMETERS);
				}
			}
			else if (strcmp(*(argv_std + 2), "/Fail") == 0)
			{
				if (strcmp(*(argv_std + 3), "/?") == 0)
				{
					printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
					printf_s("/Inquire /Fail\n\n");
					printf_s("\tStatistics list a course exam students.\n\n\n");
				}
				else
				{
					printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
					printf_s("Error: 87\n\n");
					printf_s("The parameter is incorrect.\n");
					exit(ERROR_ILLEGAL_PARAMETERS);
				}
			}
			else
			{
				printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
				printf_s("Error: 87\n\n");
				printf_s("The parameter is incorrect.\n");
				exit(ERROR_ILLEGAL_PARAMETERS);
			}
		}
		else if (strcmp(*(argv_std + 1), "/Modify") == 0)
		{
			if (strcmp(*(argv_std + 2), "/Grade_s") == 0)
			{
				if (strcmp(*(argv_std + 3), "/?") == 0)
				{
					printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
					printf_s("/Modify /Grade_s\n\n");
					printf_s("\tModify the student course information.\n\n\n");
				}
				else
				{
					printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
					printf_s("Error: 87\n\n");
					printf_s("The parameter is incorrect.\n");
					exit(ERROR_ILLEGAL_PARAMETERS);
				}
			}
			else
			{
				printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
				printf_s("Error: 87\n\n");
				printf_s("The parameter is incorrect.\n");
				exit(ERROR_ILLEGAL_PARAMETERS);
			}
		}
		else if (strcmp(*(argv_std + 1), "/Delete") == 0)
		{
			if (strcmp(*(argv_std + 2), "/Student") == 0)
			{
				if (strcmp(*(argv_std + 3), "/?") == 0)
				{
					printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
					printf_s("/Delete /Student\n\n");
					printf_s("\tDelete all the information a student.\n\n\n");
				}
				else
				{
					printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
					printf_s("Error: 87\n\n");
					printf_s("The parameter is incorrect.\n");
					exit(ERROR_ILLEGAL_PARAMETERS);
				}
			}
			else if (strcmp(*(argv_std + 2), "/Class_s") == 0)
			{
				if (strcmp(*(argv_std + 3), "/?") == 0)
				{
					printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
					printf_s("/Delete /Class_s\n\n");
					printf_s("\tDelete student course information.\n\n\n");
				}
				else
				{
					printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
					printf_s("Error: 87\n\n");
					printf_s("The parameter is incorrect.\n");
					exit(ERROR_ILLEGAL_PARAMETERS);
				}
			}
			else
			{
				printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
				printf_s("Error: 87\n\n");
				printf_s("The parameter is incorrect.\n");
				exit(ERROR_ILLEGAL_PARAMETERS);
			}
		}
	}
	// The program exits if illegal parameters exist
	else
	{
		printf_s("\nStudent Management Application\nVersion: 10.0.16170.1000\n\n\n");
		printf_s("Error: 87\n\n");
		printf_s("The parameter is incorrect.\n");
		exit(ERROR_ILLEGAL_PARAMETERS);
	}
	return NULL;
}

// Enter student information
node * __cdecl InputStudent(_Inout_ node *phead, _In_ char confirm)
{
	FILE *fp;
	// If opening the binary file "sinfo.bin" in the write mode successfully
	if (fopen_s(&fp, ".\\sinfo.bin", "w") == NULL)
	{
		node *point = phead;
		// Use default values for students or assign values to them via keyboard
		// and write them to the binary file until reaching the tail
		while (true)
		{
			// Switch to the thread that the user prefers
			switch (confirm)
			{
			case 'Y':
			case 'y':
				srand((unsigned)time(NULL));
				SAssign(point, _DEFAULT_RANDOM(_SNO_MAX, _STEP_DEFAULT, _OFFSET_DEFAULT), _SNAME_DEFAULT, 'F' + _DEFAULT_RANDOM(_SEX_OPTION, _SEX_STEP, _OFFSET_DEFAULT), _DEFAULT_RANDOM(_AGE_MAX, _STEP_DEFAULT, _OFFSET_DEFAULT), _NATION_DEFAULT);
				break;
			case 'N':
			case 'n':
			default:
				printf_s("\nEnter student information\n");
				printf_s("\n<student number>");
				scanf_s("%d", &point->sinfo->sno);
				getchar();
				printf_s("\n<student name>");
				gets_s(point->sinfo->sname);
				printf_s("\n<sex>");
				point->sinfo->sex = getchar();
				getchar();
				printf_s("\n<age>");
				scanf_s("%d", &point->sinfo->age);
				getchar();
				printf_s("\n<nation>");
				gets_s(point->sinfo->nation);
				break;
			}
			fwrite(point->sinfo, sizeof(student), 1, fp);
			// Stop from assigning values to students or write them to the binary file if reaching the tail
			if (point->next == phead || point->next == NULL)
			{
				break;
			}
			point = point->next;
		}
		fclose(fp);
	}
	return phead;
}

// Enter course information
node * __cdecl InputClass_s(_Inout_ node *phead, _In_ char confirm)
{
	FILE *fp;
	// If opening the binary file "cinfo.bin" in the write mode successfully
	if (fopen_s(&fp, ".\\cinfo.bin", "w") == NULL)
	{
		node *point = phead;
		while (true)
		{
			switch (confirm)
			{
			case 'Y':
			case 'y':
				srand((unsigned)time(NULL));
				CAssign(point, _DEFAULT_RANDOM(_CNO_MAX, _STEP_DEFAULT, _OFFSET_DEFAULT), _CNAME_DEFAULT, (double)(_DEFAULT_RANDOM(_CREDIT_MAX, _STEP_DEFAULT, _OFFSET_DEFAULT)));
				break;
			case 'N':
			case 'n':
			default:
				printf_s("\nEnter class_s information\n");
				printf_s("\n<class_s number>");
				scanf_s("%d", &point->cinfo->cno);
				getchar();
				printf_s("\n<class_s name>");
				gets_s(point->cinfo->cname);
				printf_s("\n<credit>");
				scanf_s("%lf", &point->cinfo->credit);
				getchar();
				break;
			}
			fwrite(point->cinfo, sizeof(class_s), 1, fp);
			if (point->next == phead || point->next == NULL)
			{
				break;
			}
			point = point->next;
		}
		fclose(fp);
	}
	return phead;
}

// Enter student achievement information
node * __cdecl InputGrade_s(_Inout_ node *phead, _In_ char confirm)
{
	FILE *fp;
	// If opening the binary file "ginfo.bin" in the write mode successfully
	if (fopen_s(&fp, ".\\ginfo.bin", "w") == NULL)
	{
		node *point = phead;
		while (true)
		{
			switch (confirm)
			{
			case 'Y':
			case 'y':
				srand((unsigned)time(NULL));
				GAssign(point, _DEFAULT_RANDOM(_SNO_MAX, _STEP_DEFAULT, _OFFSET_DEFAULT), _DEFAULT_RANDOM(_CNO_MAX, _STEP_DEFAULT, _OFFSET_DEFAULT), (double)(_DEFAULT_RANDOM(_GRADE_MAX, _STEP_DEFAULT, _OFFSET_DEFAULT)));
				break;
			case 'N':
			case 'n':
			default:
				printf_s("\nEnter grade_s information\n");
				printf_s("\n<student number>");
				scanf_s("%d", &point->ginfo->sno);
				getchar();
				printf_s("\n<class_s number>");
				scanf_s("%d", &point->ginfo->cno);
				getchar();
				printf_s("\n<grade>");
				scanf_s("%lf", &point->ginfo->grade);
				getchar();
				break;
			}
			fwrite(point->ginfo, sizeof(grade_s), 1, fp);
			if (point->next == phead || point->next == NULL)
			{
				break;
			}
			point = point->next;
		}
		fclose(fp);
	}
	return phead;
}

// Query the number of students
size_t __cdecl InquireNumber(_In_ node *phead)
{
	size_t count = 0;
	node *point = phead;
	// Add one to the number of students until reaching the tail
	while (true)
	{
		count++;
		// Stop from adding one to the number of students if reaching the tail
		if (point->next == phead || point->next == NULL)
		{
			break;
		}
		point = point->next;
	}
	return count;
}

// Query of grade in an elective course
double __cdecl InquireGrade_s(_In_ node *phead, _In_ int sno, _In_ int cno)
{
	node *point = phead;
	// Checking if the student number and the class_s number are available in the link list until reaching the tail
	while (true)
	{
		// Capture the corresponding grade if they are available at the same time
		if (sno == point->ginfo->sno && cno == point->ginfo->cno)
		{
			return point->ginfo->grade;
			break;
		}
		// Check complete if reaching the tail
		if (point->next == phead || point->next == NULL)
		{
			break;
		}
		point = point->next;
	}
	return ERROR_SNO_CNO_NOT_FOUND;
}

// Statistics the number of minority students
int * __cdecl InquireMinority(_In_ node *phead, _Inout_ node *Mphead, _Inout_ int *count)
{
	int *pcount = count;
	node *point = phead, *Mpoint = Mphead, *Mpointpoint;
	// Add nations that didn't appear before to the "nation" category until reaching the tail
	while (true)
	{
		Mpointpoint = Mphead;
		// Check if the nation exists in the "nation" category
		while (true)
		{
			// Ignore if the nation exists in the "nation" category
			if (strcmp(Mpointpoint->sinfo->nation, point->sinfo->nation) == 0)
			{
				break;
			}
			// Check complete if exceeded
			if (strcmp(Mpointpoint->next->sinfo->nation, _STRING_DEFAULT) == 0)
			{
				break;
			}
			Mpointpoint = Mpointpoint->next;
		}
		// Add the nation to the "nation" category if it doesn't exist
		if (strcmp(Mpointpoint->sinfo->nation, point->sinfo->nation) != 0)
		{
			strcpy_s(Mpoint->sinfo->nation, point->sinfo->nation);
		}
		Mpoint = Mpoint->next;
		// Stop from adding nations to the "nation" category if reaching the tail
		if (point->next == phead || point->next == NULL)
		{
			break;
		}
		point = point->next;
	}
	Mpoint = Mphead;
	// Statistics of the numbers of minorities until exceeded
	while (true)
	{
		point = phead;
		// Check if nations are available in the "nation" category until reaching the tail
		while (true)
		{
			// Add one to the numbers of minorities if the nation is available in the "nation" category
			if (strcmp(point->sinfo->nation, Mpoint->sinfo->nation) == 0)
			{
				(*pcount)++;
			}
			// Check complete if reaching the tail
			if (point->next == phead || point->next == NULL)
			{
				break;
			}
			point = point->next;
		}
		pcount++;
		// Stop from statistics of the numbers of minorities if exceeded
		if (strcmp(Mpoint->next->sinfo->nation, _STRING_DEFAULT) == 0)
		{
			break;
		}
		Mpoint = Mpoint->next;
	}
	return count;
}

// Statistics list a course exam students
int * __cdecl InquireFail(_In_ node *phead, _Inout_ int *sno, _In_ int cno)
{
	int *psno = sno;
	node *point = phead;
	// Assign student numbers until reaching the tail
	while (true)
	{
		// Capture the student number if the grade of the class_s number given is less than 60
		if (point->ginfo->grade < 60 && point->ginfo->cno == cno)
		{
			*psno = point->ginfo->sno;
		}
		psno++;
		// Stop from assigning student numbers if reaching the tail
		if (point->next == phead || point->next == NULL)
		{
			break;
		}
		point = point->next;
	}
	return sno;
}

// Modify the student course information
double __cdecl ModifyGrade_s(_Inout_ node *phead, _In_ int sno, _In_ int cno, _In_ double grade)
{
	node *point = phead;
	// Checking if the student number and the class_s number are available in the link list until reaching the tail
	while (true)
	{
		// Modify the corresponding grade if they are available at the same time
		if (sno == point->ginfo->sno && cno == point->ginfo->cno)
		{
			point->ginfo->grade = grade;
			return point->ginfo->grade;
			break;
		}
		// Check complete if reaching the tail
		if (point->next == phead || point->next == NULL)
		{
			break;
		}
		point = point->next;
	}
	return NULL;
}

// Delete all the information a student
node * __cdecl DeleteStudent(_Inout_ node *phead, _In_ node *ptail, _In_ int sno)
{
	node *point = phead;
	// Checking if the student number is available in the link list until reaching the tail
	while (true)
	{
		// Dismiss the corresponding node if available
		if (sno == point->sinfo->sno || sno == point->ginfo->sno)
		{
			point->back->next = point->next;
			point->next->back = point->back;
			// Change the head if the head was dismissed
			if (point == phead)
			{
				phead = point->next;
			}
			// Change the tail if the tail was dismissed
			if (point == ptail)
			{
				ptail = point->back;
			}
			{
				free(point->sinfo);
				free(point->cinfo);
				free(point->ginfo);
			}
			free(point);
		}
		// Check complete if reaching the tail
		if (point->next == phead || point->next == NULL)
		{
			break;
		}
		point = point->next;
	}
	FILE *fps, *fpc, *fpg;
	// If opening the binary files in the write mode successfully
	if (fopen_s(&fps, ".\\sinfo.bin", "w") == NULL && fopen_s(&fpc, ".\\cinfo.bin", "w") == NULL && fopen_s(&fpg, ".\\ginfo.bin", "w") == NULL)
	{
		fseek(fps, 0L, SEEK_SET);
		fseek(fpc, 0L, SEEK_SET);
		fseek(fpg, 0L, SEEK_SET);
		point = phead;
		// Write student information, class_s information and grade_s information to the binary files until reaching the tail
		while (true)
		{
			fwrite(point->sinfo, sizeof(student), 1, fps);
			fwrite(point->cinfo, sizeof(class_s), 1, fpc);
			fwrite(point->ginfo, sizeof(grade_s), 1, fpg);
			// Stop from writing information to the binary files if reaching the tail
			if (point->next == phead || point->next == NULL)
			{
				break;
			}
			point = point->next;
		}
		fclose(fps);
		fclose(fpg);
	}
	return phead;
}

// Delete student course information
node * __cdecl DeleteClass_s(_Inout_ node *phead, _In_ node *ptail, _In_ int cno)
{
	node *point = phead;
	// checking if the class_s number is available in the link list until reaching the tail
	while (true)
	{
		// Dismiss the corresponding node if available
		if (cno == point->cinfo->cno || cno == point->ginfo->cno)
		{
			point->back->next = point->next;
			point->next->back = point->back;
			// Change the head if the head was dismissed
			if (point == phead)
			{
				phead = point->next;
			}
			// Change the tail if the tail was dismissed
			if (point == ptail)
			{
				ptail = point->back;
			}
			{
				free(point->sinfo);
				free(point->cinfo);
				free(point->ginfo);
			}
			free(point);
		}
		// Check complete if reaching the tail
		if (point->next == phead || point->next == NULL)
		{
			break;
		}
		point = point->next;
	}
	FILE *fps, *fpc, *fpg;
	// If opening the binary files in the write mode successfully
	if (fopen_s(&fps, ".\\sinfo.bin", "w") == NULL && fopen_s(&fpc, ".\\cinfo.bin", "w") == NULL && fopen_s(&fpg, ".\\ginfo.bin", "w") == NULL)
	{
		fseek(fps, 0L, SEEK_SET);
		fseek(fpc, 0L, SEEK_SET);
		fseek(fpg, 0L, SEEK_SET);
		point = phead;
		// Write student information, class_s information and grade_s information to the binary files until reaching the tail
		while (true)
		{
			fwrite(point->sinfo, sizeof(student), 1, fps);
			fwrite(point->cinfo, sizeof(class_s), 1, fpc);
			fwrite(point->ginfo, sizeof(grade_s), 1, fpg);
			// Stop from writing information to the binary files if reaching the tail
			if (point->next == phead || point->next == NULL)
			{
				break;
			}
			point = point->next;
		}
		fclose(fps);
		fclose(fpg);
	}
	return phead;
}

// Free memory allocated for the link list
node * __cdecl FreeAll(_In_ node *phead)
{
	if (InquireNumber(phead) > 1)
	{
		node *point = phead->next->next;
		// Free the back nodes until reaching the head
		while (true)
		{
			// Free memory allocated for sub categories
			{
				free(point->back->sinfo);
				free(point->back->cinfo);
				free(point->back->ginfo);
			}
			free(point->back);
			// Stop from freeing the back nodes if reaching the head
			if (point == phead || point == NULL)
			{
				break;
			}
			point = point->next;
		}
	}
	// Free the head
	{
		free(phead->sinfo);
		free(phead->cinfo);
		free(phead->ginfo);
	}
	free(phead);
	return NULL;
}

// Assign values to student
node * __cdecl SAssign(_Inout_ node *current, _In_ int sno, _In_z_ char *sname, _In_ char sex, _In_ int age, _In_z_ char *nation)
{
	current->sinfo->sno = sno;
	strcpy_s(current->sinfo->sname, sname);
	current->sinfo->sex = sex;
	current->sinfo->age = age;
	strcpy_s(current->sinfo->nation, nation);
	return current;
}

// Assign values to class_s
node * __cdecl CAssign(_Inout_ node *current, _In_ int cno, _In_z_ char *cname, _In_ double credit)
{
	current->cinfo->cno = cno;
	strcpy_s(current->cinfo->cname, cname);
	current->cinfo->credit = credit;
	return current;
}

// Assign values to grade_s
node * __cdecl GAssign(_Inout_ node *current, _In_ int sno, _In_ int cno, _In_ double grade)
{
	current->ginfo->sno = sno;
	current->ginfo->cno = cno;
	current->ginfo->grade = grade;
	return current;
}

// Switch cases to reach alignment to the parameters the user enters
char * __cdecl Alignment(_Out_writes_z_(_String_length_(sour) + 1) char *dest, _In_z_ char *sour)
{
	size_t i = 0;
	*dest = *sour;
	// Copy from source to destination until reaching the end of the string
	// Stop from copying if reaching the end of the string
	while (*++sour != NULL)
	{
		*(dest + ++i) = *sour;
	}
	*(dest + ++i) = NULL;
	sour = dest;
	// Ignore if dest[0] doesn't equal '/' or the string length is less than 2
	if (*sour == '/' && *++sour != NULL)
	{
		// Switch dest[1] to the upper case if necessary
		if (*sour >= 'a' && *sour <= 'z')
		{
			*sour += 'A' - 'a';
		}
		// Checking if characters belong to upper cases until reaching the end of the string
		// Check complete if reaching the end of the string
		while (*++sour != NULL)
		{
			// Switch characters to lower cases if necessary
			if (*sour >= 'A' && *sour <= 'Z')
			{
				*sour += 'a' - 'A';
			}
		}
	}
	return dest;
}

