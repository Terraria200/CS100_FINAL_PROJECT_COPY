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
![image](https://github.com/cs100/final-project-gwils018-haham003-kwils076-nster005/assets/68349014/d4596197-86cc-44af-bdab-753c53b34e99)

Our Quiz Class allows us to create a quiz from scratch or upload one. Our questions will be made into a vector with each one being a Question object, our score will be tracked and changed using an integer variable, and our user inputted answers will all be typed into a string variable. Each question has a string that is the content of the question and another string with it's correct answer, and we have several member functions to set the correct answer, check the user inputted answer against the correct answer, and then change the score based on whether or not the answer was correct or not. Under the Question class, we have separate classes for our separate types of questions: multiple choice, fill-in-the-blank, and True or False. For Multiple Choice, we have a vector of strings for our 4 options (a-d), and we can also shuffle the mutiple choice options around with shuffleOptions(). For Fill-in-the-Blank and True/False, we simply check the user-inputted answer against the correct answer before changing the score based on whether the user had the right answer or not. For Fill-in-the-Blank, we may also use the toUpper() function to remove the need for correct capitalization.
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
