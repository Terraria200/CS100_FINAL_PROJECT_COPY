add_library(simpleLibrary
  Fill-in-the-Blank.cpp
  main.cpp
  MultiChoice.cpp
  Question.cpp
  Quiz.cpp
  QuizConstructor.cpp
  True-or-False.cpp
  QuizManager.cpp
)

add_executable(application
Fill-in-the-Blank.cpp
main.cpp
MultiChoice.cpp
Question.cpp
Quiz.cpp
QuizConstructor.cpp
True-or-False.cpp
QuizManager.cpp
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})