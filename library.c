// #include <stdio.h>
// #include <stdlib.h>
// #include<string.h>
// #include <time.h>

// #define MAX_LEVEL 9

// // typedef struct book{
// //     char name[100];
// //     char author[50];
// //     int id;
// //     int no_ofCopies;
// // }BOOK;


// // A structure called DATE that has data members as date,month and year
// typedef struct date{
//     int date;
//     int month;
//     int year;
// }DATE;

// // structure called BORROW_DETAILS taht has book id and duedate as datamembers.
// // duedate is of type sturcture DATE , since DATE will be in the form of date/month/year.
// typedef struct borrow_details{
//     int bookId;
//     DATE dueDate;
//     // int issued;
// }BORROW_DETAILS;

// // Student Node Structure
// //A structure called STUDENT that contains the student details like name,prn(last 4 digits), details(this is of type BORROW_DETAILS,bcz 
// //details include the details of students bookid and duedate ),rear in order to insert , and forward to connect to the next student.

// typedef struct student{
//     char name[50];
//     int PRN;
//     BORROW_DETAILS details[3];
//     int rear;
//     struct student** forward;
// }STUDENT;

// // Skip List Structure
// //A struture of skiplist , (imagine it as an array of skip lists) that has level and pointer of type strudent.
// typedef struct SkipList {
//     int level;
//     struct student* header;
// }SKIPLIST;

// // Calculate the due date as 14 days from the current date
// DATE calculateDueDate() {
//     time_t currentTime; //currentTime is a variable of type time_t.time_t is typically used to represnt time in seconds
//     struct tm* dueDateInfo; // dueDateInfo is of type struct tm*,which is defined in time.h header file.struct tm is a 
//     //structure that has date and time as its members.
//     time(&currentTime); // this retirives the current time in seconds since the epoch(jan 1, 1970) and stores in current time variable.


//     // Get the current time and add 14 days
//     currentTime += 14 * 24 * 60 * 60;  // 14 days in seconds

//     dueDateInfo = localtime(&currentTime);
//     //Converts the modified currentTime to a calendar time and stores it in the tm structure pointed to by dueDateInfo.
//     DATE dueDate;//Declares a variable dueDate of type DATE.
//     dueDate.date = dueDateInfo->tm_mday;
//     dueDate.month = dueDateInfo->tm_mon + 1;  // tm_mon is 0-based
//     dueDate.year = dueDateInfo->tm_year + 1900;  // tm_year is years since 1900

//     return dueDate;// returns the calculated due date as a DATE structure.
// }

// //This is the function which give sthe issue_details of the student.
// //function has rear and pointer called studentNode of type STUDENT* struture.
// void issueDetails(int rear,STUDENT* studentNode){
//     char choice='y';
//     // The condition in while , says that if the student enters y or Y saying they want to issue one more book
//     // and then one more condition to take care the student havent issued more than 3 books.
//     while ((choice == 'y' || choice=='Y') && studentNode->rear <2)
//     {
//         // if above condition is true, increment the rear and store the details.
//          studentNode->rear++;
//         printf("Enter Book ID: ");
//         scanf("%d",&studentNode->details[studentNode->rear].bookId);// array of structures.
//         studentNode->details[studentNode->rear].dueDate = calculateDueDate();
//         // printf("%d\n",studentNode->rear);

//         //After issuing the book, if still the rear is less 2 , then ask student whther he want to issue one more book.
//         if(studentNode->rear<2){
//             printf("Do you have to issue another book? (y/n)? ");
//             scanf(" %c",&choice);
//             while(!(choice=='y' || choice=='Y'|| choice=='n' || choice=='N')){
//                 printf("Please Enter a Valid choice!! (y/n): ");
//                 scanf(" %c",&choice);
//             }
//         }
//     }
//     printf("\nBOOK(s) ISSUED\nThank You! \n\n\n");
// }


// // Function to create a new Student node
// struct student* createStudentNode(int header,int PRN,int level) {
//     struct student* newNode = (struct student*)malloc(sizeof(struct student)); // memory allocation for newnode.
//     //struct student* sturcture is used.

//     if (newNode == NULL) {
//         printf("Memory allocation failed.\n");
//         return NULL;
//     }
//     if(header==1){
//         newNode->PRN=PRN;
//     }else{
//         newNode->rear=-1;
        
//         printf("Enter Student Name: ");
//         scanf(" %49[^\n]",&newNode->name);
//         newNode->PRN=PRN;

//         for (int i = 0; i < 3; i++) {
//             newNode->details[i].bookId = -1; // Initialize bookId to -1 for all books
//         }

//         printf("\nBOOK DETAILS:\n");

//         issueDetails(newNode->rear,newNode);

//         // char choice='y';
//         // while (choice == 'y' && newNode->rear <=2){
//         //     printf("Enter Book ID: ");
//         //     scanf("%d",&newNode->details[newNode->rear].bookId);
//         //     newNode->details[newNode->rear].dueDate = calculateDueDate();
//         //     newNode->rear++;
//         //     if(newNode->rear<=2){
//         //         printf("Do you have to issue another book? (y/n)? ");
//         //         scanf(" %c",&choice);
//         //     }
//         // }
//         // printf("Thank You!\n\n");
//     }

//     newNode->forward = (struct student*)malloc(sizeof(struct student) * (level + 1));
//     return newNode;
// }

// // Function to create a new Skip List
// struct SkipList* createSkipList() {
//     struct SkipList* list = (struct SkipList*)malloc(sizeof(struct SkipList)); //memory allocation
//     list->level = 0; //Initializes the level property of the skip list to 0. The level typically 
//     //represents the maximum level of any node in the skip list.
//     list->header = createStudentNode(1,-1, MAX_LEVEL);

//     for (int i = 0; i <= MAX_LEVEL; i++) {
//         list->header->forward[i] = NULL;
//     }

//     return list;
// }

// // Function to generate a random level for a new node
// //This implementation generates a random level by incrementing 
// //the level as long as the value returned by rand() is less than
// // half of RAND_MAX (which is the maximum value returned by rand())
// // and the current level is less than MAX_LEVEL. 
// //The probability of increasing the level decreases as the value returned by rand() increases.
// int randomLevel() {
//     int level = 0;
//     while (rand() < RAND_MAX / 2 && level < MAX_LEVEL) {
//         level++;
//     }
//     return level;


//     // float r = (float)rand()/RAND_MAX;
//     // int level = 0;
//     // while (r < P && lvl < MAXLVL)
//     // {
//     //     lvl++;
//     //     r = (float)rand()/RAND_MAX;
//     // }
//     // return level;

// }

// // Function to insert a key into the Skip List
// void insert(struct SkipList* list, int PRN)
//  {
//     //declare an array of pointers to struct student named update with a size of MAX_LEVEL + 1. 
//     //current is a pointer to the header node of the skip list.

//     struct student* update[MAX_LEVEL + 1];
//     struct student* current = list->header;

//     for (int i = list->level; i >= 0; i--)
//     //You start a loop that iterates through the levels of the skip list, 
//     //starting from the highest level and going down to the base level. 
//     {
//         while (current->forward[i] != NULL && current->forward[i]->PRN < PRN) {
//             current = current->forward[i];
//         }//traverse the forward pointers until you find a node with PRN value greater than
//         //or equal to the target PRN or youreach the end of the level.
//         //You store the nodes encounteres in the 'update array 
//         update[i] = current;
//     }

//     current = current->forward[0];//set current to the forward pointer at the base level.

//     if (current == NULL || current->PRN != PRN) {
//         int newLevel = randomLevel();
//         //generate a random level for the new node using the randomLevel function. 
//         //This level determines the height of the new node in the skip list.

//         if (newLevel > list->level) 
//         //If the new level is greater than the current level of the skip list,
//         // you update the update array for the new levels, and you set the skip list's level to the new level.
//         {
//             for (int i = list->level + 1; i <= newLevel; i++) {
//                 update[i] = list->header;
//             }
//             list->level = newLevel;
//         }
//         //after finding a newlevel,newnode is created by calling create_node function.
//         struct student* newNode = createStudentNode(0,PRN,newLevel);

//         for (int i = 0; i <= newLevel; i++) {
//             newNode->forward[i] = update[i]->forward[i];
//             update[i]->forward[i] = newNode;
//         }
//         //You update the forward pointers of the nodes in the update array to point to the new node, 
//         //and you update the forward pointers of the new node to point to the nodes that were in the update array.
//         //this inserts the newnode into the skiplist at the appropriate positions.
//     }   
// }


// // Function to search for a value in the Skip List
// STUDENT* search(struct SkipList* list, int PRN)//it searches based upon teh PRN
//  {
//     STUDENT* current = list->header;//initialize a pointer current to the header node of the skip list.

//     for (int i = list->level; i >= 0; i--)//start a loop that iterates through the levels of the skip list, starting from the highest level and going down to the base level. 
//     {
//         while (current->forward[i] != NULL && current->forward[i]->PRN < PRN)
//         //Within each level, you traverse the forward pointers until you find a node with a PRN value greater than
//         // or equal to the target PRN or you reach the end of the level.
//         {
//             current = current->forward[i];
//         }
//     }

//     current = current->forward[0];//After completing the loop, you set current to the forward pointer at the base level.



//     //if the current node is not NULL and has the target PRN. 
//     //If so, you return a pointer to that node; otherwise, 
//     //you return NULL, indicating that the PRN value was not found in the skip list.
//     if (current != NULL && current->PRN == PRN)
//      {
//         return current; // Found the PRN value
//     } else {
//         return NULL;    // PRN value not found
//     }
// }


// //Function prints the that specific students details like
// // their name,PRN,and already stores details(i.e,previously isuued books details)
// void print_student_details(STUDENT* studentNode){
//     printf("Name: %s\n", studentNode->name);
//     printf("PRN: %d\n",studentNode->PRN);
//     printf("\nPREVIOUSLY BORROWED DETAILS:\n");
//     for(int j=0;j<=studentNode->rear && j<3;j++){
//         if (studentNode->details[j].bookId > -1) {
//             printf("Book ID: %d\t",studentNode->details[j].bookId);
//             printf("DueDate: %d/%d/%d\n",studentNode->details[j].dueDate.date, 
//             studentNode->details[j].dueDate.month, studentNode->details[j].dueDate.year);
//         }
//     }
// }

// void issue (struct SkipList* list){
//     int PRN;
//     printf("Enter Student PRN Number (Last 4 digits): ");
//     scanf("%d",&PRN);//take input of PRN

//     STUDENT* thisStudent=search(list,PRN);//calling a function named search with the skip list (list) and 
//     //the entered PRN as parameters. The result is stored in the thisStudent pointer
//     //search function searches for a student with a given PRN in the skiplist.

//     if(thisStudent==NULL)// checks if the student is not found in the skip list, if the student is not found in the skiplist,
//     //then insert a new student with the given PRN into the skiplist.
//     {
//         insert(list,PRN);
//     }else{
//         //if student is found then it prints the student details.
//         print_student_details(thisStudent);
//         printf("\n");
        
//          //if the student has already issued 3 books,the it says no more books can be issued.
//         if(thisStudent->rear>=2){
//             printf("!NO MORE BOOKS CAN BE BORROWED!\n\n");
//         }
//         //if the issued books are not 3 and less thean that, then it calls issuedetails function for  student to issue book.
//         else{
//             issueDetails(thisStudent->rear,thisStudent);
//         }
//     }
// }

// // Function to print the Skip List
// void printSkipList(struct SkipList* list) {
//     printf("Skip List (level %d):\n", list->level);
//     for (int i = list->level; i >= 0; i--) {
//         struct student* current = list->header->forward[i];
//         printf("Level %d:\n", i);
//         while (current != NULL) {
//             printf("Name: %s\n", current->name);
//             printf("PRN: %d\n",current->PRN);
//             printf("BOOK DETAILS:\n");
//             for(int j=0;j<=current->rear && j<3;j++){
//                 if (current->details[j].bookId > -1) {
//                     printf("Book ID: %d\t",current->details[j].bookId);
//                     printf("DueDate: %d/%d/%d\n",current->details[j].dueDate.date, 
//                     current->details[j].dueDate.month, current->details[j].dueDate.year);
//                 }
//             }
//             current = current->forward[i];
//         }
//         printf("\n\n");
//     }
// }

// void load_data(struct SkipList* list,char name[],int PRN,int bookid1,int dueDate1D,int dueDate1M,int dueDate1Y,
//     int bookid2,int dueDate2D,int dueDate2M,int dueDate2Y,int bookid3,int dueDate3D,int dueDate3M,int dueDate3Y,int rear){
//     struct student* update[MAX_LEVEL + 1];//: Declares an array of pointers named update to store nodes at different levels
//     // in the skip list during the insertion process.
//     struct student* current = list->header;
//     //Initializes a pointer named current to the header node of the skip list. This will be used to traverse the 
//     //skip list during the insertion process.



//     //Initiates a loop that iterates from the top level to the bottom level of the skip list. The loop
//     // is used to find the correct position to insert the new node.
//     for (int i = list->level; i >= 0; i--) {
//         while (current->forward[i] != NULL && current->forward[i]->PRN < PRN) {
//             current = current->forward[i];
//         } // In each level, iterates forward in the skip list until 
//         //it finds the correct position to insert the new node. It compares the PRN of the existing node with the PRN of the new node.
       
       
//         update[i] = current;
//         //Stores the current node in the update array for the current level. 
//         //This is used to update the forward pointers during the insertion.
//     }

//     current = current->forward[0];
//     //Moves current to the level-0 forward node,
//     // which is the potential insertion point for the new node.

//     if (current == NULL || current->PRN != PRN)//checks whether the new node with the specified PRN already exists in the skip list.
//      {
//         int newLevel = randomLevel();//Generates a random level for the new node using a function called randomLevel. 
//         //This random level determines the height of the new node in the skip list.

//         if (newLevel > list->level)
//         //If the random level is greater than the current level of the skip list,
//         // updates the update array to include the header node for the new levels and updates the skip list level.
//          {
//             for (int i = list->level + 1; i <= newLevel; i++) {
//                 update[i] = list->header;
//             }
//             list->level = newLevel;
//         }

//         struct student* newNode = (struct student*)malloc(sizeof(struct student));// allocates memory for new stuednt node
//         strcpy(newNode->name,name); //copies student name to newnode.
//         newNode->PRN=PRN;// Assigns the PRN to the new node.
//         // assign bookids anf date to the newnode.
//         newNode->details[0].bookId=bookid1;
//         newNode->details[0].dueDate.date=dueDate1D;
//         newNode->details[0].dueDate.month=dueDate1M;
//         newNode->details[0].dueDate.year=dueDate1Y;
//         newNode->details[1].bookId=bookid2;
//         newNode->details[1].dueDate.date=dueDate2D;
//         newNode->details[1].dueDate.month=dueDate2M;
//         newNode->details[1].dueDate.year=dueDate2Y;
//         newNode->details[2].bookId=bookid3;
//         newNode->details[2].dueDate.date=dueDate3D;
//         newNode->details[2].dueDate.month=dueDate3M;
//         newNode->details[2].dueDate.year=dueDate3Y;
//         newNode->rear=rear;//assigns the rear property to the new node.

//         newNode->forward = (struct student*)malloc(sizeof(struct student) * (newLevel + 1));
//         //allocates memory for forward pointers based on the new level.


//         for (int i = 0; i <= newLevel; i++)
//         {
//             newNode->forward[i] = update[i]->forward[i];
//             update[i]->forward[i] = newNode;
//         }
//         //Updates the forward pointers of the new node and the nodes in the update array for the new levels.
//     }
// }

// void freeSkipList(struct SkipList* list) {
//     if (list == NULL) {
//         return; // Skip list is already empty
//     }

//     struct student* current = list->header->forward[0];
//     while (current != NULL) {
//         struct student* next = current->forward[0]; // Store the next node

//         // Free the forward array and the current node
//         free(current->forward);
//         free(current);

//         current = next;
//     }

//     // Free the header node and the skip list itself
//     free(list->header->forward);
//     free(list->header);
//     free(list);
// }

// void delete(struct SkipList* list, int PRN){
//     //we declare an array of pointers to student struct and a current pointer
//     // that points to the header of the skip list
//     struct student* update[MAX_LEVEL + 1];
//     struct student* current = list->header;

//     //loop iterates from top to bottom of the skip list level
//     for (int i = list->level; i >= 0; i--) {
//         while (current->forward[i] != NULL && current->forward[i]->PRN < PRN) {
//             current = current->forward[i];
//         }
//         update[i] = current;
//     }
//     //Within each level, we traverse the forward pointers until we
//     // find a node with a PRN value greater than or equal to the target
//    // PRN or we reach the end of the level. we store the nodes encountered in the update array.

//     current = current->forward[0];//set current to the forward pointer at the base level.

//     if (current != NULL && current->PRN == PRN)// checks if the current node is not  null and has teh atrget PRN.
//     //if its true ,then we found our PRN in the skiplist to delete
//      {
//         // Remove the node from the list
//         for (int i = 0; i <= list->level; i++) {
//             if (update[i]->forward[i] != current) {
//                 break;
//             }
//             update[i]->forward[i] = current->forward[i];
//         }
//         free(current);//free the memory occupied by the node with the delted PRN

//         // Update the level if needed
//         //check if the skip lists level needs to be updated and if needed
//         // decrement the level.
//         while (list->level > 0 && list->header->forward[list->level] == NULL) {
//             list->level--;
//         }
//     }
//     printf("Node deleted successfully");
// }

// void return_book (struct SkipList* list){
//     int PRN;
//     printf("Enter Student PRN Number (Last 4 digits): ");
//     scanf("%d",&PRN); //take PRN input

//     STUDENT* thisStudent=search(list,PRN);
//     //checks if the student with entered PRN has previously isuued book or no
//     //If students has not issued any books, then print no data
//     //if its there then execute else block.

//     if(thisStudent==NULL){
//         printf("Seems as if the the student has not borrowed any book!!\nKindly verify the PRN!!");
//     }else{
//         //if student found print details of student 
//         print_student_details(thisStudent);
//         // printf("\n%d",thisStudent->rear);
//         char return_choice='y';
//         //asking if he wants to return

//         while ((return_choice=='y' || return_choice=='Y') && thisStudent->rear>-1){
//             int BookID;
//             //if the student previously issued only one book
//             //then without asking him the bookid, just return that book.
//             //if not then asks the bookid in the else block.
//             if(thisStudent->rear==0){
//                 char choice='y';
//                 BookID=thisStudent->details->bookId;
//                 printf("\nDo you need to return the book with ID %d ? (y/n) : ",BookID);
//                 scanf(" %c",&choice);
//                 while(!(choice=='y' || choice=='Y'|| choice=='n' || choice=='N')){
//                     printf("Please Enter a Valid choice!! (y/n): ");
//                     scanf(" %c",&choice);
//                 }
//                 if(choice=='n' || choice=='N'){
//                     printf("\nOkay Thank you!");
//                     return;
//                 }
//             }else{
//                 printf("\nEnter ID of the Book to be returned: ");
//                 scanf("%d",&BookID);
//                 //if the bookId is not present in  any of the three ,it prints to enter valid id.
//                 //if its present , then again the control goes to while loop and executes.
//                 while(!(BookID==thisStudent->details[0].bookId || BookID==thisStudent->details[1].bookId || BookID==thisStudent->details[2].bookId)){
//                     printf("There is no Book issued under that ID! Please Enter one of the above displayed IDs: ");
//                     scanf("%d",&BookID);
//                 }
//             }
//             for(int i=0;i<=thisStudent->rear;i++){      //Iteratively searches for match in BookID
//                 if(thisStudent->details[i].bookId==BookID){
//                     for(int j=i;j< 2;j++){        //Iteratively shifts the lower elements upwards
//                         thisStudent->details[j]=thisStudent->details[j+1];
//                     }
//                     thisStudent->details[thisStudent->rear].bookId=-1; //Sets the ID of the returned book(i.e Book pointed by rear)to -1
//                     thisStudent->rear--;       
//                     break;
//                 }
//             }
//             //Here, we search for the book with the entered ID (BookID) in the details of the student. 
//             //If found, we shift the lower elements upwards to remove the returned book's details,
//             // and decrease the rear count.
//             printf("\nBook (ID: %d) returned Successfully!\n",BookID);

//             if(thisStudent->rear>-1){
//                 printf("Do you want to return another book? (y/n)? ");
//                 scanf(" %c",&return_choice);
//                 while(!(return_choice=='y' || return_choice=='Y'|| return_choice=='n' || return_choice=='N')){
//                     printf("Please Enter a Valid choice!! (y/n): ");
//                     scanf(" %c",&return_choice);
//                 }
//             }//if the choice is y or Y then agin the control goes to while.
//         }                                                                                                     
//     }
//     // print_student_details(thisStudent);
//     // printf("\n%d",thisStudent->rear);
//     printf("\nBOOK(s) RETURNED\nTHANK YOU!!");
// }

// void renew(struct SkipList* list,int PRN,int bookId)
// {
//     //search for PRN if exists in teh skiplist
//     STUDENT* thisStudent=search(list,PRN);
    
//     //if its not there then , give message that not found
//     if(thisStudent==NULL)
//     {
//        printf("Student with PRN %d not found\n",PRN);
//        return;
//     }

//     //Check if the student has issued the specified book
//     int bookIndex=-1;
//     for(int i=0;i<=thisStudent->rear;i++)
//     {
//         if(thisStudent->details[i].bookId==bookId)
//         {
//             bookIndex=i;
//             break;
//         }
//     }
//     if(bookIndex==-1)
//     {
//         printf("Student with PRN %d has not issued a book with ID %d\n",PRN,bookId);
//         return;
//     }
    
//      thisStudent->details[bookIndex].dueDate = calculateDueDate();
//      printf("%d due date\n",thisStudent->details[bookIndex].dueDate);
//     printf("Book with ID %d renewed successfully for student with PRN %d!\n", bookId, PRN);

    
// }

// void write_data_to_file(struct SkipList* list) {
//     FILE* fp = fopen("books.csv", "w");
//     if (fp == NULL) {
//         perror("Error opening file for writing");
//         return;
//     }

//     fprintf(fp, "Name,PRN,Book1 ID,Book1 DueDate,Book2 ID,Book2 DueDate,Book3 ID,Book3 DueDate,Rear\n");

//     struct student* current = list->header->forward[0];
//     while (current != NULL) {
//         fprintf(fp, "%s,%d,%d,%d/%d/%d,%d,%d/%d/%d,%d,%d/%d/%d,%d\n",
//                 current->name, current->PRN,
//                 current->details[0].bookId, current->details[0].dueDate.date, current->details[0].dueDate.month, current->details[0].dueDate.year,
//                 current->details[1].bookId, current->details[1].dueDate.date, current->details[1].dueDate.month, current->details[1].dueDate.year,
//                 current->details[2].bookId, current->details[2].dueDate.date, current->details[2].dueDate.month, current->details[2].dueDate.year,
//                 current->rear);

//         current = current->forward[0];
//     }

//     // Flush the buffer
//     fflush(fp);

//     if (fclose(fp) != 0) {
//         perror("Error closing file");
//     }
//     printf("Data written to 'books.csv' successfully.\n");
// }


// int main(){
//     srand(time(NULL));//we are setting the seed for the random number generator based on the current time.
//     // Since the time is constantly changing, this helps in generating a different sequence of random numbers 
//     //each time the program is run. Without this line or without setting a new seed, the rand() function would 
//     //produce the same sequence of numbers every time the program is executed, which might not be desirable,
//     // especially in situations where you want randomness.

//     struct SkipList* list = createSkipList();// creating the skipist.
//     FILE* fp= fopen("books.csv","r+");
//     //open a file named "stud_details.csv" in read and write mode (r+).
//     // If the file opening is successful, it returns a pointer to the file (fp), otherwise, it prints an error message.
//     if(fp==NULL){
//         printf("Failed to load Student Data!!\n");
//     }else{
//         char line[500];
//         fgets(line,500,fp); //reads line by line using fgets and parses each line using sscanf.
//         //
//         //fputs(line,stdout);

//         while(fgets(line,500,fp)){

//             char name[50];
//             int PRN,bookid1,bookid2,bookid3,dueDate1D,dueDate2D,dueDate3D,
//             dueDate1M,dueDate2M,dueDate3M,dueDate1Y,dueDate2Y,dueDate3Y,rear;
            
//             //sscanf is a function in C that stands for "scan formatted." It is used to read data 
//             //from a string according to a specified format and store the extracted values into specified variables. 
//             //The function is part of the C Standard Library and is declared in the header file stdio.h.


//            // syntax=> int sscanf(const char *str, const char *format, ...);

//             if (sscanf(line, "%50[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
//              name,&PRN, &bookid1,&dueDate1D,&dueDate1M,&dueDate1Y,&bookid2,&dueDate2D,&dueDate2M,&dueDate2Y,
//              &bookid3,&dueDate3D,&dueDate3M,&dueDate3Y,&rear) == 15) {
//                 // Call the function and pass the parsed values as arguments
//                 load_data(list,name,PRN,bookid1,dueDate1D,dueDate1M,dueDate1Y,
//                 bookid2,dueDate2D,dueDate2M,dueDate2Y,bookid3,dueDate3D,dueDate3M,dueDate3Y,rear);
//                 //  printf("%s,%d,%d,%d/%d/%d,%d,%d/%d/%d,%d,%d/%d/%d,%d\n",name,PRN,bookid1,dueDate1D,dueDate1M,dueDate1Y,
//                 //  bookid2,dueDate2D,dueDate2M,dueDate2Y,bookid3,dueDate3D,dueDate3M,dueDate3Y,rear);
//              }else{
//                 printf("Failed to parse the CSV row!!\n");
//             }
        
//         }
//         // printSkipList(list);
//         fclose(fp);//close the file using fclose(fp) after reading the data.
//     }
//     int choice;
//     do {
//         printf("\n***** Library Management System *****\n");
//         printf("1. Issue a Book\n");
//         printf("2. Return a Book\n");
//         printf("3. Renew a Book\n");
//         printf("4. Print Skip List\n");
//         printf("5. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 issue(list);
//                 break;

//             case 2:
//                 return_book(list);
//                 break;

//             case 3:
//                 // Renew a Book
//                 {
//                     int PRN, bookId;
//                      printf("Enter Student PRN Number (Last 4 digits): ");
//                     scanf("%d", &PRN);
//                     printf("Enter Book ID to renew: ");
//                     scanf("%d", &bookId);
//                     renew(list, PRN, bookId);
//                 }
//                 break;

//             case 4:
//                 printSkipList(list);
//                 break;

//             case 5:
//                 break;
//              default:
//                 printf("Invalid choice! Please enter a number between 1 and 5.\n");
//         }

//     } while (choice != 5);

//     write_data_to_file(list);
//     freeSkipList(list);



//     return 0;
// }



// // insert_student_to_list---done
// // delete_student_from_list---done
// // search_student_from_list---done

// // issue---done
// // renewal
// // return---done

// // new_stock
// // sort_by_dueDate
// // change due date

// // librarian_login
// // student_login

// //load_data---done
// //write_data

// //free_skiplist---done
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>

#define MAX_LEVEL 9
#define NUMBER_OF_BOOKS 30

// A structure called DATE that has data members as date,month and year
typedef struct date{
    int date;
    int month;
    int year;
}DATE;

// structure called BORROW_DETAILS that has book id and duedate as datamembers.
// duedate is of type sturcture DATE , since DATE will be in the form of date/month/year.
typedef struct borrow_details{
    int bookId;
    DATE dueDate;
    // int issued;
}BORROW_DETAILS;

// Student Node Structure
//A structure called STUDENT that contains the student details like name,PRN(last 4 digits), details(this is of type BORROW_DETAILS,bcz 
//details include the details of students bookid and duedate ),rear in order to insert , and forward to connect to the next student.
typedef struct student{
    char name[50];
    int PRN;
    BORROW_DETAILS details[3];
    int rear;
    struct student** forward;
}STUDENT;

// Skip List Structure
typedef struct SkipList {
    int level;
    struct student* header;
}SKIPLIST;

typedef struct Hash
{
    int book_id;
    int copies;
}HASH;

HASH* a[NUMBER_OF_BOOKS]; //create a hash table
int n1=0;

int H(int k)
{
    int h=0;
    h=k%NUMBER_OF_BOOKS;
    return h;
}

int searchi(int id)
{
    if(n1==0)
        return 0;
    int i=0;
    int index=H(id);

    while(a[index] && a[index]->book_id != id && i<NUMBER_OF_BOOKS)
    {
        printf("%d", index);
        index=(index+1)%NUMBER_OF_BOOKS;
		i++;
    }

    if(a[index] && a[index]->book_id == id)
    {
        return index+1;
    }
    else
    {
        return 0;
    }
}


void initial()
{
    for(int i=0;i<NUMBER_OF_BOOKS;i++)
    {
        a[i] = NULL;
    }
}


int insert_intoHash(int id,int d)
{
    if(NUMBER_OF_BOOKS==n1)
		return 0;
	int index=H(id);
    int i=0;
	while(a[index]!=NULL && i<NUMBER_OF_BOOKS)
    {
		index=(index+1)%NUMBER_OF_BOOKS;
        i++;
    }
    HASH* n2=(HASH*)malloc(sizeof(HASH));
    n2->copies=d;
	n2->book_id=id;
    a[index]=n2;
	n1++;
	return 1;
}

int delete_fromHash(int id)
{
    if(n1==0){
        return 0;
    }
    int i=0;
    int index=H(id);
    while(a[index]->book_id!=id && i<n1)
    {
        index=(index+1)%NUMBER_OF_BOOKS;
		i++;
    }

    if(a[index]->book_id==id)
    {
        free(a[index]);
        a[index] = NULL;
        n1--;
        return 1;
    }
    return 0;
}

void incrementor(int id, int d) {
    printf("%d",id);
    int g=0;
    g=searchi(id);
    if(g==0)
    {
        insert_intoHash(id,d);
    }
    else
    {
        g=g-1;
        a[g]->copies+=d;
        printf("\nNumber of Copies remaining of Book ID %d is: %d",id,a[g]->copies);
    }
}

void freeMemory() 
{
    for (int i = 0; i < NUMBER_OF_BOOKS; i++) {
        if (a[i] != NULL) {
            free(a[i]);
        }
    }
}

void load(FILE* fp1)
{
    fprintf(fp1,"%s,%s","BookId","Copies");
    for(int i=0;i<NUMBER_OF_BOOKS;i++)
    {
        if(a[i]!=NULL)
        {
            fprintf(fp1,"\n%d,%d",a[i]->book_id,a[i]->copies);
        }
    }
    fclose(fp1);
}


void issued(int id)
{
    int g;
    if(searchi(id)!=0)
    {
        g=searchi(id)-1;
        a[g]->copies-=1;
    }
    else
    {
        printf("Book Not Found\n");
    }
}

void ret(int id)
{
    int g;
    if(searchi(id)!=0)
    {
        g=searchi(id)-1;
        a[g]->copies+=1;
    }
    else
    {
        printf("Book Not Found\n");
    }
}

// Calculate the due date as 14 days from the current date
DATE calculateDueDate() {
    time_t currentTime;         //currentTime is a variable of type time_t.time_t is typically used to represnt time in seconds
    struct tm* dueDateInfo;     // dueDateInfo is of type struct tm*,which is defined in time.h header file.struct tm is a 
                                //structure that has date and time as its members.
    time(&currentTime); // this retirives the current time in seconds since the epoch(jan 1, 1970) and stores in current time variable.


    // Get the current time and add 14 days
    currentTime += 14 * 24 * 60 * 60;  // 14 days in seconds

    dueDateInfo = localtime(&currentTime);
    //Converts the modified currentTime to a calendar time and stores it in the tm structure pointed to by dueDateInfo.

    DATE dueDate;       //Declares a variable dueDate of type DATE.
    dueDate.date = dueDateInfo->tm_mday;
    dueDate.month = dueDateInfo->tm_mon + 1;  // tm_mon is 0-based
    dueDate.year = dueDateInfo->tm_year + 1900;  // tm_year is years since 1900

    return dueDate;     // returns the calculated due date as a DATE structure.
}

//This is the function which gives the issue_details of the student.
//function has rear and pointer called studentNode of type STUDENT* struture.
void issueDetails(int rear,STUDENT* studentNode){
    char choice='y';
    // The condition in while , says that if the student enters y or Y saying they want to issue one more book
    // and then one more condition to take care the student havent issued more than 3 books.
    while ((choice == 'y' || choice=='Y') && studentNode->rear <2){
        // if above condition is true, increment the rear and store the details.
        studentNode->rear++;
        printf("Enter Book ID: ");
        scanf("%d",&studentNode->details[studentNode->rear].bookId);       // array of structures.
        studentNode->details[studentNode->rear].dueDate = calculateDueDate();
        issued(studentNode->details[studentNode->rear].bookId);
        // printf("%d\n",studentNode->rear);
        
        //After issuing the book, if still the rear is less 2 , then ask student whther he want to issue one more book.
        if(studentNode->rear<2){
            printf("Do you have to issue another book? (y/n)? ");
            scanf(" %c",&choice);
            while(!(choice=='y' || choice=='Y'|| choice=='n' || choice=='N')){
                printf("Please Enter a Valid choice!! (y/n): ");
                scanf(" %c",&choice);
            }
        }
    }
    printf("\nBOOK(s) ISSUED\nThank You! \n\n\n");
}


// Function to create a new Student node
struct student* createStudentNode(int header,int PRN,int level) {
    struct student* newNode = (struct student*)malloc(sizeof(struct student));      // memory allocation for newnode.
    //struct student* sturcture is used.
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    if(header==1){
        newNode->PRN=PRN;
    }else{
        newNode->rear=-1;
        
        printf("Enter Student Name: ");
        scanf(" %49[^\n]",&newNode->name);
        newNode->PRN=PRN;

        for (int i = 0; i < 3; i++) {
            newNode->details[i].bookId = -1; // Initialize bookId to -1 for all books
        }

        printf("\nBOOK DETAILS:\n");

        issueDetails(newNode->rear,newNode);

        // char choice='y';
        // while (choice == 'y' && newNode->rear <=2){
        //     printf("Enter Book ID: ");
        //     scanf("%d",&newNode->details[newNode->rear].bookId);
        //     newNode->details[newNode->rear].dueDate = calculateDueDate();
        //     newNode->rear++;
        //     if(newNode->rear<=2){
        //         printf("Do you have to issue another book? (y/n)? ");
        //         scanf(" %c",&choice);
        //     }
        // }
        // printf("Thank You!\n\n");
    }

    newNode->forward = (struct student*)malloc(sizeof(struct student) * (level + 1));
    return newNode;
}

// Function to create a new Skip List
struct SkipList* createSkipList() {
    struct SkipList* list = (struct SkipList*)malloc(sizeof(struct SkipList));       //memory allocation
    list->level = 0;        //Initializes the level property of the skip list to 0. The level typically 
    //represents the maximum level of any node in the skip list.
    list->header = createStudentNode(1,-1, MAX_LEVEL);

    for (int i = 0; i <= MAX_LEVEL; i++) {
        list->header->forward[i] = NULL;
    }

    return list;
}

// Function to generate a random level for a new node
//This implementation generates a random level by incrementing 
//the level as long as the value returned by rand() is less than
// half of RAND_MAX (which is the maximum value returned by rand())
// and the current level is less than MAX_LEVEL. 
//The probability of increasing the level decreases as the value returned by rand() increases.
int randomLevel() {
    int level = 0;
    while (rand() < RAND_MAX / 2 && level < MAX_LEVEL) {
        level++;
    }
    return level;


    // float r = (float)rand()/RAND_MAX;
    // int level = 0;
    // while (r < P && lvl < MAXLVL)
    // {
    //     lvl++;
    //     r = (float)rand()/RAND_MAX;
    // }
    // return level;

}

// Function to insert a key into the Skip List
void insert(struct SkipList* list, int PRN) {
    //declare an array of pointers to struct student named update with a size of MAX_LEVEL + 1. 
    //current is a pointer to the header node of the skip list.
    struct student* update[MAX_LEVEL + 1];
    struct student* current = list->header;

    for (int i = list->level; i >= 0; i--)
    //You start a loop that iterates through the levels of the skip list, 
    //starting from the highest level and going down to the base level. 
    {
        while (current->forward[i] != NULL && current->forward[i]->PRN < PRN) {
            current = current->forward[i];
        }//traverse the forward pointers until you find a node with PRN value greater than
        //or equal to the target PRN or youreach the end of the level.
        //You store the nodes encounteres in the 'update array 
        update[i] = current;
    }

    current = current->forward[0];      //set current to the forward pointer at the base level.

    if (current == NULL || current->PRN != PRN) {
        int newLevel = randomLevel();
        //generate a random level for the new node using the randomLevel function. 
        //This level determines the height of the new node in the skip list.

        if (newLevel > list->level) 
        //If the new level is greater than the current level of the skip list,
        // you update the update array for the new levels, and you set the skip list's level to the new level.
        {
            for (int i = list->level + 1; i <= newLevel; i++) {
                update[i] = list->header;
            }
            list->level = newLevel;
        }
        //after finding a newlevel,newnode is created by calling create_node function.
        struct student* newNode = createStudentNode(0,PRN,newLevel);

        for (int i = 0; i <= newLevel; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
        //You update the forward pointers of the nodes in the update array to point to the new node, 
        //and you update the forward pointers of the new node to point to the nodes that were in the update array.
        //this inserts the newnode into the skiplist at the appropriate positions.
    }
}


// Function to search for a value in the Skip List
STUDENT* search(struct SkipList* list, int PRN) {       //it searches based on the PRN
    STUDENT* current = list->header;                    //initialize a pointer current to the header node of the skip list.


    //start a loop that iterates through the levels of the skip list, starting from the highest level and going down to the base level.
    for (int i = list->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->PRN < PRN) 
        //Within each level, you traverse the forward pointers until you find a node with a PRN value greater than
        // or equal to the target PRN or you reach the end of the level.
        {
            current = current->forward[i];      
        }
    }

    current = current->forward[0];      //After completing the loop, you set current to the forward pointer at the base level.


    //if the current node is not NULL and has the target PRN. 
    //If so, you return a pointer to that node; otherwise, 
    //you return NULL, indicating that the PRN value was not found in the skip list.
    if (current != NULL && current->PRN == PRN) {
        return current; // Found the PRN value
    } else {
        return NULL;    // PRN value not found
    }
}


//Function prints the that specific students details like
// their name,PRN,and already stores details(i.e,previously isuued books details)
void print_student_details(STUDENT* studentNode){
    if(studentNode==NULL){
        printf("No Student found under the specified PRN!\n");
        return;
    }
    printf("Name: %s\n", studentNode->name);
    printf("PRN: %d\n",studentNode->PRN);
    printf("\nPREVIOUS BORROW DETAILS:\n");
    for(int j=0;j<=studentNode->rear && j<3;j++){
        if (studentNode->details[j].bookId > -1) {
            printf("Book ID: %d\t",studentNode->details[j].bookId);
            printf("DueDate: %d/%d/%d\n",studentNode->details[j].dueDate.date, 
            studentNode->details[j].dueDate.month, studentNode->details[j].dueDate.year);
        }
    }
}

void issue (struct SkipList* list){
    int PRN;
    printf("Enter Student PRN Number (Last 4 digits): ");
    scanf("%d",&PRN);
    STUDENT* thisStudent=search(list,PRN);  //calling a function named search with the skip list (list) and 
    //the entered PRN as parameters. The result is stored in the thisStudent pointer
    //search function searches for a student with a given PRN in the skiplist.

    if(thisStudent==NULL){  // checks if the student is not found in the skip list, if the student is not found in the skiplist,
    //then insert a new student with the given PRN into the skiplist.
        insert(list,PRN);
    }else{
        //if student is found then it prints the student details.
        print_student_details(thisStudent);
        printf("\n");
        
         //if the student has already issued 3 books,the it says no more books can be issued.
        if(thisStudent->rear>=2){
            printf("!NO MORE BOOKS CAN BE BORROWED!\n\n");
        }else{
            issueDetails(thisStudent->rear,thisStudent);
        }
    }
}

// Function to print the Skip List
void printSkipList(struct SkipList* list) {
    printf("Skip List (level %d):\n", list->level);
    for (int i = list->level; i >= 0; i--) {
        struct student* current = list->header->forward[i];
        printf("Level %d:\n", i);
        while (current != NULL) {
            printf("Name: %s\n", current->name);
            printf("PRN: %d\n",current->PRN);
            printf("BOOK DETAILS:\n");
            for(int j=0;j<=current->rear && j<3;j++){
                if (current->details[j].bookId > -1) {
                    printf("Book ID: %d\t",current->details[j].bookId);
                    printf("DueDate: %d/%d/%d\n",current->details[j].dueDate.date, 
                    current->details[j].dueDate.month, current->details[j].dueDate.year);
                }
            }
            current = current->forward[i];
        }
        printf("\n\n");
    }
}

void load_data(struct SkipList* list,char name[],int PRN,int bookid1,int dueDate1D,int dueDate1M,int dueDate1Y,
    int bookid2,int dueDate2D,int dueDate2M,int dueDate2Y,int bookid3,int dueDate3D,int dueDate3M,int dueDate3Y,int rear){
    struct student* update[MAX_LEVEL + 1];  // Declares an array of pointers named update to store nodes at different levels
    // in the skip list during the insertion process.
    struct student* current = list->header;     
    //Initializes a pointer named current to the header node of the skip list. This will be used to traverse the 
    //skip list during the insertion process.


    //Initiates a loop that iterates from the top level to the bottom level of the skip list. The loop
    // is used to find the correct position to insert the new node.
    for (int i = list->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->PRN < PRN) {
            current = current->forward[i];
        }
        // In each level, iterates forward in the skip list until 
        //it finds the correct position to insert the new node. It compares the PRN of the existing node with the PRN of the new node.
        
        update[i] = current;
        //Stores the current node in the update array for the current level. 
        //This is used to update the forward pointers during the insertion.
    }

    current = current->forward[0];      
    //Moves current to the level-0 forward node,
    // which is the potential insertion point for the new node.

    if (current == NULL || current->PRN != PRN) {  //checks whether the new node with the specified PRN already exists in the skip list.
        int newLevel = randomLevel();       //Generates a random level for the new node using a function called randomLevel. 
        //This random level determines the height of the new node in the skip list.

        if (newLevel > list->level) //If the random level is greater than the current level of the skip list,
        // updates the update array to include the header node for the new levels and updates the skip list level.
        {
            for (int i = list->level + 1; i <= newLevel; i++) {
                update[i] = list->header;
            }
            list->level = newLevel;
        }

        struct student* newNode = (struct student*)malloc(sizeof(struct student));  // allocates memory for new stuednt node
        strcpy(newNode->name,name);     //copies student name to newnode.
        newNode->PRN=PRN;               // Assigns the PRN to the new node.
        // assign bookids anf date to the newnode.
        newNode->details[0].bookId=bookid1;
        newNode->details[0].dueDate.date=dueDate1D;
        newNode->details[0].dueDate.month=dueDate1M;
        newNode->details[0].dueDate.year=dueDate1Y;
        newNode->details[1].bookId=bookid2;
        newNode->details[1].dueDate.date=dueDate2D;
        newNode->details[1].dueDate.month=dueDate2M;
        newNode->details[1].dueDate.year=dueDate2Y;
        newNode->details[2].bookId=bookid3;
        newNode->details[2].dueDate.date=dueDate3D;
        newNode->details[2].dueDate.month=dueDate3M;
        newNode->details[2].dueDate.year=dueDate3Y;
        newNode->rear=rear;     //assigns the rear property to the new node.
        newNode->forward = (struct student*)malloc(sizeof(struct student) * (newLevel + 1));
        //allocates memory for forward pointers based on the new level.

        for (int i = 0; i <= newLevel; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
        //Updates the forward pointers of the new node and the nodes in the update array for the new levels.
    }
}

void freeSkipList(struct SkipList* list) {
    if (list == NULL) {
        return; // Skip list is already empty
    }

    struct student* current = list->header->forward[0];
    while (current != NULL) {
        struct student* next = current->forward[0]; // Store the next node

        // Free the forward array and the current node
        free(current->forward);
        free(current);

        current = next;
    }

    // Free the header node and the skip list itself
    free(list->header->forward);
    free(list->header);
    free(list);
}

void delete(struct SkipList* list, int PRN){
    //we declare an array of pointers to student struct and a current pointer
    // that points to the header of the skip list
    struct student* update[MAX_LEVEL + 1];
    struct student* current = list->header;
    
    //loop iterates from top to bottom of the skip list level
    for (int i = list->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->PRN < PRN) {
            current = current->forward[i];
        }
        update[i] = current;
    }
    //Within each level, we traverse the forward pointers until we
    // find a node with a PRN value greater than or equal to the target
   // PRN or we reach the end of the level. we store the nodes encountered in the update array.

    current = current->forward[0];  //set current to the forward pointer at the base level.

    if (current != NULL && current->PRN == PRN)     // checks if the current node is not  null and has the target PRN.
                                                    //if its true ,then we found our PRN in the skiplist to delete
    {
        // Remove the node from the list
        for (int i = 0; i <= list->level; i++) {
            if (update[i]->forward[i] != current) {
                break;
            }
            update[i]->forward[i] = current->forward[i];
        }
        free(current);      //free the memory occupied by the node with the delted PRN

        // Update the level if needed
        //check if the skip lists level needs to be updated and if needed
        // decrement the level.
        while (list->level > 0 && list->header->forward[list->level] == NULL) {
            list->level--;
        }
    }
    // printf("Node deleted successfully");
}

void return_book (struct SkipList* list){
    int PRN;
    printf("Enter Student PRN Number (Last 4 digits): ");
    scanf("%d",&PRN);
    STUDENT* thisStudent=search(list,PRN);
    //checks if the student with entered PRN has previously isuued book or no
    //If students has not issued any books, then print no data
    //if its there then execute else block.

    if(thisStudent==NULL){
        printf("Seems as if the the student has not borrowed any book!!\nKindly verify the PRN!!");
    }else{
        //if student found print details of student 
        print_student_details(thisStudent);
        // printf("\n%d",thisStudent->rear);
        char return_choice='y';
        //asking if he wants to return

        while ((return_choice=='y' || return_choice=='Y') && thisStudent->rear>-1){
            int BookID;
            //if the student previously issued only one book
            //then without asking him the bookid, just return that book.
            //if not then asks the bookid in the else block.

            if(thisStudent->rear==0){
                char choice='y';
                BookID=thisStudent->details->bookId;
                printf("\nDo you need to return the book with ID %d ? (y/n) : ",BookID);
                scanf(" %c",&choice);
                while(!(choice=='y' || choice=='Y'|| choice=='n' || choice=='N')){
                    printf("Please Enter a Valid choice!! (y/n): ");
                    scanf(" %c",&choice);
                }
                if(choice=='n' || choice=='N'){
                    printf("\nOkay Thank you!");
                    return;
                }
            }else{
                printf("\nEnter ID of the Book to be returned: ");
                scanf("%d",&BookID);
                //if the bookId is not present in  any of the three ,it prints to enter valid id.
                //if its present , then again the control goes to while loop and executes.
                while(!(BookID==thisStudent->details[0].bookId || BookID==thisStudent->details[1].bookId || BookID==thisStudent->details[2].bookId)){
                    printf("There is no Book issued under that ID! Please Enter one of the above displayed IDs: ");
                    scanf("%d",&BookID);
                }
            }
            for(int i=0;i<=thisStudent->rear;i++){      //Iteratively searches for match in BookID
                if(thisStudent->details[i].bookId==BookID){
                    for(int j=i;j< 2;j++){        //Iteratively shifts the lower elements upwards
                        thisStudent->details[j]=thisStudent->details[j+1];
                    }
                    thisStudent->details[thisStudent->rear].bookId=-1; //Sets the ID of the returned book(i.e Book pointed by rear)to -1
                    thisStudent->rear--;   
                    ret(BookID);
                    // printf("\n%d",thisStudent->rear); 
                    if (thisStudent->rear == -1) {
                        // If rear is -1, delete the student node
                        delete(list, PRN);
                    }
                }
            }
            //Here, we search for the book with the entered ID (BookID) in the details of the student. 
            //If found, we shift the lower elements upwards to remove the returned book's details,
            // and decrease the rear count.
            printf("\nBook (ID: %d) returned Successfully!\n",BookID);
            printf("All books returned for Student with PRN %d. Student node deleted.\n", PRN);

            if(thisStudent->rear>-1){
                printf("Do you have to return another book? (y/n)? ");
                scanf(" %c",&return_choice);
                while(!(return_choice=='y' || return_choice=='Y'|| return_choice=='n' || return_choice=='N')){
                    printf("Please Enter a Valid choice!! (y/n): ");
                    scanf(" %c",&return_choice);
                }
            }   //if the choice is y or Y then agin the control goes to while.
        }                                                                                                     
    }
    // print_student_details(thisStudent);
    // printf("\n%d",thisStudent->rear);
    printf("\nBOOK(s) RETURNED\nTHANK YOU!!");
}

void renew(struct SkipList* list)
{
    int PRN, bookId;
    printf("Enter Student PRN Number (Last 4 digits): ");
    scanf("%d", &PRN);
    //search for PRN if exists in the skiplist
    STUDENT* thisStudent=search(list,PRN);
    
    //if its not there then , give message that not found
    if(thisStudent==NULL)
    {
       printf("Student with PRN %d not found\n",PRN);
       return;
    }

    printf("\n");
    print_student_details(thisStudent);

    printf("\nEnter Book ID to renew: ");
    scanf("%d", &bookId);

    //Check if the student has issued the specified book
    int bookIndex=-1;
    for(int i=0;i<=thisStudent->rear;i++)
    {
        if(thisStudent->details[i].bookId==bookId)
        {
            bookIndex=i;
            break;
        }
    }
    if(bookIndex==-1)
    {
        printf("Student with PRN %d has not issued a book with ID %d\n",PRN,bookId);
        return;
    }
    
     thisStudent->details[bookIndex].dueDate = calculateDueDate();
     printf("Next DueDate: %d/%d/%d \n",thisStudent->details[bookIndex].dueDate.date,
     thisStudent->details[bookIndex].dueDate.month,thisStudent->details[bookIndex].dueDate.year);
     printf("Book with ID %d renewed successfully for student with PRN %d!\n", bookId, PRN);

}

void write_data_to_file(struct SkipList* list) {
    FILE* fp = fopen("student_details.csv", "w");  // Open in write mode to overwrite the file
    if (fp == NULL) {
        perror("Error opening file for writing");
        return;   // Exit the program 
    }

    // Write the header
    fprintf(fp, "Name,PRN,bookid1,dueDate1D,dueDate1M,dueDate1Y,bookid2,dueDate2D,dueDate2M,dueDate2Y,bookid3,dueDate3D,dueDate3M,dueDate3Y,rear\n");

    // Write the data back to the file
    struct student* current = list->header->forward[0];
    while (current != NULL) {
        fprintf(fp, "%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
                current->name, current->PRN,
                current->details[0].bookId, current->details[0].dueDate.date, current->details[0].dueDate.month, current->details[0].dueDate.year,
                current->details[1].bookId, current->details[1].dueDate.date, current->details[1].dueDate.month, current->details[1].dueDate.year,
                current->details[2].bookId, current->details[2].dueDate.date, current->details[2].dueDate.month, current->details[2].dueDate.year,
                current->rear);

        current = current->forward[0];
    }

    // Flush the buffer
    fflush(fp);

    if (fclose(fp) != 0) {
        perror("Error closing file");
    }
    printf("Data written back to file successfully.\n");
}

void bookInStock(){
    int bookID;
    printf("Enter Book ID: ");
    scanf("%d",&bookID);
    int g=0;
    g=searchi(bookID);
    g-=1;
    printf("\nNumber of Copies remaining of Book ID %d is: %d\n",bookID,a[g]->copies);
    if(a[g]->copies==0){
        printf("No more copies of the book left!!\n");
    }
}




int main(){
    srand(time(NULL));
    //we are setting the seed for the random number generator based on the current time.
    // Since the time is constantly changing, this helps in generating a different sequence of random numbers 
    //each time the program is run. Without this line or without setting a new seed, the rand() function would 
    //produce the same sequence of numbers every time the program is executed, which might not be desirable,
    // especially in situations where you want randomness.

    //Creating Hashtable and inserting books into it
    initial();

    FILE* fpBook=fopen("2.csv","r");
    if(fpBook==NULL)
    {
        printf("failed to open");
        freeMemory();
    }
    else{
        char line[50]={0};
        fgets(line,500,fpBook);
        while(fgets(line,500,fpBook) != NULL)
        {
            char *val = strtok(line,",");
            char *val2 = strtok(NULL,",");
            val2[strcspn(val2, "\n")] = '\0'; //removes the newline character at the end of val2 by replacing it with the null terminator.
            int d1=atoi(val2);
            int d=atoi(val);
            insert_intoHash(d,d1);
        }
    }
    fclose(fpBook);


    struct SkipList* list = createSkipList();       // creating the skipist.
    FILE* fp= fopen("student_details.csv","r");
    //open a file named "stud_details.csv" in read mode (r).
    // If the file opening is successful, it returns a pointer to the file (fp), otherwise, it prints an error message.
    if(fp==NULL){
        printf("Failed to load Student Data!!\n");
        return 1;  // Exit the program with an error code
    }else{
        char line[500];
        fgets(line,500,fp);     // Read and discard the header
        //reads line by line using fgets and parses each line using sscanf.
        //fputs(line,stdout);

        while(fgets(line,500,fp)){

            char name[50];
            int PRN,bookid1,bookid2,bookid3,dueDate1D,dueDate2D,dueDate3D,
            dueDate1M,dueDate2M,dueDate3M,dueDate1Y,dueDate2Y,dueDate3Y,rear;

            //sscanf is a function in C that stands for "scan formatted." It is used to read data 
            //from a string according to a specified format and store the extracted values into specified variables. 
            //The function is part of the C Standard Library and is declared in the header file stdio.h.

           // syntax=> int sscanf(const char *str, const char *format, ...);
            if (sscanf(line, "%50[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
             name,&PRN, &bookid1,&dueDate1D,&dueDate1M,&dueDate1Y,&bookid2,&dueDate2D,&dueDate2M,&dueDate2Y,
             &bookid3,&dueDate3D,&dueDate3M,&dueDate3Y,&rear) == 15) {
                // Call the function and pass the parsed values as arguments
                load_data(list,name,PRN,bookid1,dueDate1D,dueDate1M,dueDate1Y,
                bookid2,dueDate2D,dueDate2M,dueDate2Y,bookid3,dueDate3D,dueDate3M,dueDate3Y,rear);
                //  printf("%s,%d,%d,%d/%d/%d,%d,%d/%d/%d,%d,%d/%d/%d,%d\n",name,PRN,bookid1,dueDate1D,dueDate1M,dueDate1Y,
                //  bookid2,dueDate2D,dueDate2M,dueDate2Y,bookid3,dueDate3D,dueDate3M,dueDate3Y,rear);
             }else{
                printf("Failed to parse the CSV row!!\n");
            }
        
        }
        // printSkipList(list);
        fclose(fp);     //close the file using fclose(fp) after reading the data.
    }
    // // for(int i=0;i<=5;i++){
    //     issue(list);
    //     return_book(list);
    // // printSkipList(list);
    // // }
    // // printSkipList(list);
    int PRN;
    int choice;

    do {
        printf("**Library Management System**\n");
        printf("1. Issue\n");
        printf("2. Renewal\n");
        printf("3. Return\n");
        printf("4. Search a Student\n");
        printf("5. Search if a Book is in Stock\n");
        printf("6. Exit\n");
        printf("Enter your choice (1/2/3/4/5/6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                issue(list);
                break;
            case 2:
                renew(list);
                break;
            case 3:
                return_book(list);
                break;
            case 4:
                printf("\nEnter Student PRN Number (Last 4 digits): ");
                scanf("%d",&PRN);
                search(list,PRN);
                STUDENT* thisStudent=search(list,PRN);
                if(thisStudent==NULL){
                    printf("Seems as if the the student has not borrowed any book!!\nKindly verify the PRN!!\n\n");
                }else{
                    print_student_details(thisStudent);
                    printf("\n");
                }
                break;
            case 5:
                bookInStock();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter 1, 2, 3, 4 or 5.\n");
        }
    } while (choice != 6);

    write_data_to_file(list);
    
    FILE* fpBook1=fopen("2.csv","w");
    load(fpBook1);
    freeMemory();
    freeSkipList(list);
    return 0;
}



// insert_student_to_list---done
// delete_student_from_list---done
// search_student_from_list---done

// issue---done
// renewal---done
// return---done

// new_stock---done
// sort_by_dueDate
// change due date---done

// librarian_login
// student_login

//load_data---done
//write_data---done

//free_skiplist---done