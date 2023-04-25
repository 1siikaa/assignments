class Library:
   def displayCategories(self):
    print(" 《 SPOOKY LIBRARY 》\n ")
    print("Available Category is { Fiction Thriller } only.\n")
   
   def __init__(self, listOfBooks):
    self.books=listOfBooks
   
   def displayAvailable(self):
    print("Welcome to 《 SPOOKY LIBRARY 》. Books present in this spooky library are:\n")
    print("_______LIBRARY MENU_______\n") 
    for index, book in enumerate (self.books):
     print("\n")
     print((index+1),book)
     print("\n")
   
   
   def borrowBook(self, bookName):
    if bookName in self.books:
     print ( f"you have been issued {bookName} Please keep it safe and return it within 30 days\n")
     self.books.remove(bookName)
     return True
    else:
     print("\n")
     print("Either this book has issued by someone else or not available at this time.\n")
     print(" OR\n ")
     print("Enter a valid book as given in the Library menu because books_name are case sensitive.\n")
     return False
   
  
   def returnBook(self, bookName):
      self.books.append(bookName)
      print("Thanks for returning or adding or donating this book! Hope you enjoyed reading it. Have a great day ahead!\n")

class Reader:
   def requestBook(self):
     self.books=input("Enter the name of the book you want to borrow\n")
     return self.books
    
   def returnBook(self):
      self.books=input("Enter the name of the book you want to return\n ")
      return self.books
   
   def yourFeedback(self):
      feedback= input("Enter Your Feedback\n")
      print("Thanks for your valuable feedback\n")
   
if __name__ == "__main__":
   spookyLibrary = Library(["400 Days","that night", "The Silent Patient ", "twisted LOVE", "twisted HATE", "twisted GAMES", "twisted LIES", "The Perfect Ruin", "The Chestnut Man", "The Sweetest Oblivion", "The Maddest Obsession", "The Darkest Temptation", "ASYLUM", "SANCTUM", "CATACOMB", "INSOMNIA (KEEP YOUR EYES OPEN)", "Word Power Made Easy", "INSOMNIA ( Sleep While You Can )"])
   reader= Reader()
   while(True):
      print("\n")
      welcomeMsg = '''       《  SPOOKY LIBRARY 》
      ° ° ° ° ° ° ° ° ° ° ° °
   
   Welcome to this library dear user
   -: Please choose an option :-
                  
   1. Available genere category.
      __________________________
   2. List all the available novels.
      _____________________________
   3. Request a novel.
      _________________
   4. Return / Add / Donate a novel.
      ______________________________
   5. Your feedback.
      ______________
   6. Exit the library.
      _________________
                   '''
      print(welcomeMsg)
      try:
       a= int(input("Enter a choice:\n"))
       if a==1:
        spookyLibrary.displayCategories()
       elif a==2:
        spookyLibrary.displayAvailable()
       elif a==3:
        spookyLibrary.borrowBook(reader.requestBook())
       elif a==4:
        spookyLibrary.returnBook(reader.returnBook())
       elif a==5:
        reader.yourFeedback()
       elif a==6:
        print("Thanks for choosing this 《 SPOOKY LIBRARY 》\n")
        print("Have a great day ahead!\n")
        print("Please do visit again\n")
        exit()
       else:
        print("Invalid choice\n")
      except TypeError as e:
        print(f"Please go through the welcomeMsg again: {e}\n ")
      except ValueError as e: 
        print(f"Please go through the welcomeMsg again: {e}\n")
      except NameError as e:
        print(f"Please go through the welcomeMsg again: {e}\n ")
     
       
       
       
            

