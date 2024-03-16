# The Mind Meld
 > Authors: [Gavin Wilson](https://github.com/EyeAmTheOne), [Haroon Ahamed](https://github.com/Terraria200), [Keanu Wilson](https://github.com/5i1v3rf0x), and [Nicholas Stermer](https://github.com/nicholasstermer)

## Project Description

> Description: User-run, fun-based trivia application meant for events like game nights and trivia nights. Users can create categorized quizzes involving flashcards with trivia questions and their respective answers.
>
> Input: User enters a trivia question with four answers (a-d), with one answer being the correct one.
>
> Output: Once a user selects an answer, the application will output whether or not that answer is correct, and if it is not, the application outputs the correct answer.
>
> Features: Can give each quiz a name. can shuffle flashcards in quiz, etc.

## User Interface Specification

### Navigation Diagram
![image](https://github.com/cs100/final-project-gwils018-haham003-kwils076-nster005/assets/68349014/94fc9238-112a-430f-a41d-d00e63f110c3)

### Screen Layouts
![image](https://github.com/cs100/final-project-gwils018-haham003-kwils076-nster005/assets/68349014/248348db-0cd8-40b2-8975-ae138a8ec9c2)
![image](https://github.com/cs100/final-project-gwils018-haham003-kwils076-nster005/assets/68349014/9dd53fcc-62b4-4b24-a3b4-b8aae0703a25)

## Class Diagram
![image](https://github.com/cs100/final-project-gwils018-haham003-kwils076-nster005/assets/68349014/14cc89b8-b6a3-42ab-ab76-e399514fddab)

Our Quiz Class allows us to create a quiz from scratch or upload one. Our questions will be made into a vector with each one being a Question object, our score will be tracked and changed using an integer variable, and our user inputted answers will all be typed into a string variable. Each question has a string that is the content of the question and another string with it's correct answer, and we have several member functions to set the correct answer, check the user inputted answer against the correct answer, and then change the score based on whether or not the answer was correct or not. Under the Question class, we have separate classes for our separate types of questions: multiple choice, fill-in-the-blank, and True or False. For Multiple Choice, we have a vector of strings for our 4 options (a-d), and we can also shuffle the mutiple choice options around with shuffleOptions(). For Fill-in-the-Blank and True/False, we simply check the user-inputted answer against the correct answer before changing the score based on whether the user had the right answer or not. For Fill-in-the-Blank, we may also use the toUpper() function to remove the need for correct capitalization.
 
SOLID Principle Changes explanation:
* Single responsibility - The Quiz constructor was originally responsible for uploading and downloading both JSON and TXT files, we separated the two file types into separate classes that inherit from a QuizConstructor interface.  This helped us by categorizing the behaviors for each type of QuizConstructor,and will also allow us to create more types in the future.
* Interface segregation - Originally, the Question class was originally forcing each subclass to have a string implementation for their answer, this did not make sense so we removed the implementation from the interface and put them into the individual subclasses.  This allows each subclass to implement its own type of answer that works better with the behavior that is specific to that subclass.
* Dependency inversion - Originally, the Quiz class methods would output to the std cout and take inputs from the std cin.  Rather than doing this now, we have changed the method to take references to input and output streams as parameters, which allows us to not depend on which specific stream we are outputting the quiz display to.  This has helped us while devoloping because it allowed us to more easily write tests for this function, and it gives the function more flexibility with what it is capable of.
 
 ## Screenshots
 Creating a Quiz:
 
 ![image](https://github.com/cs100/final-project-gwils018-haham003-kwils076-nster005/assets/68349014/6bbec974-a0e0-4020-ad69-51c739ce1b50)

 Taking a Quiz:
 
 ![image](https://github.com/cs100/final-project-gwils018-haham003-kwils076-nster005/assets/68349014/9e483e3e-b981-4110-926e-c5f0a0cfc053)

 Downloading a Quiz:
 
 ![image](https://github.com/cs100/final-project-gwils018-haham003-kwils076-nster005/assets/68349014/7f8c2f1b-92ce-45c6-8e8d-1ac802139321)
 ![image](https://github.com/cs100/final-project-gwils018-haham003-kwils076-nster005/assets/68349014/06f1fd24-1f73-49da-bf07-eb9f6e3e127f)

 Uploading a Quiz:
 
 ![image](https://github.com/cs100/final-project-gwils018-haham003-kwils076-nster005/assets/68349014/3056655e-d43a-42d8-af68-928289eae0aa)
 ![image](https://github.com/cs100/final-project-gwils018-haham003-kwils076-nster005/assets/68349014/289a9117-a8db-4ef8-b9e9-bd4fc8e97b5a)

 



 ## Installation/Usage
1. Download Visual Studio (VS) Code for your computer.
2. Press the button at the bottom left of VS Code, then press “Connect to the Host,” “+ Add New SSH Host,” and then enter in “ssh <your_CS_username>@cs100.cs.ucr.edu” Afterwards, connect to the host by logging in with your CS password.
3. At the top left of your screen, press the 2nd button from the top to access the “Explorer”
4. Under “Explorer,” you will see the option to clone a repository. Click on that and you will be directed to provide a repository URL or source from GitHub.
5. Clone the repository into your desired folder using its url: “https://github.com/cs100/final-project-gwils018-haham003-kwils076-nster005.git”
6. Press “Control (or Command) + Shift + P” to access the menu of options. Select “Terminal: Create New Terminal”
7. Clone in the googleTest repository using “git submodule add https://github.com/google/googletest.git” for testing and running purposes
8. Place the newly created "googletest" folder into the "test" folder. Ensure that it is the only "googletest" folder inside of there and that there is a "CMakeLists.txt" file inside of it.
9. Run these commands to compile, test, and run the application: “cmake.”, “make”, “./bin/runAllTests”, “./bin/application”. The valgrind command we use to ensure no memory leaks is "valgrind --leak-check=full ./bin/runAllTests ./bin/application"

 ## Testing
 We used Google Testing and thus unit tests to validate that our outputs to the screen were correct and that certain values like scores and answers were correct.
 
