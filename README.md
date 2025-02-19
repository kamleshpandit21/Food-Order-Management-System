Restaurant Management System

Introduction

The Restaurant Management System is a simple console-based application developed in C that allows for menu management, order placement, and user/admin authentication. It offers separate modes for users and admins, facilitating functionalities such as dish management, registration, login, and order processing.
Features

A.User Mode

   1.User Registration

   2.User Authentication/Login

   3.View Menu

   4.Place Orders
   
B.Admin Mode

  1.Admin Authentication/Login

  2.Add Dishes to Menu

  3.Remove Dishes from Menu

  4.View Menu

  5.View Registered Users

  6.View Registered Staff

  7.Add Admin Members

C.File Structure

  Source Code:foodOrderManegement.c

  Data Files:

    users.txt: Stores registered user data

    admin_membar.txt: Stores registered admin data

    food_menu.txt: Stores the menu items

    temp_menu.txt: Temporary file used during menu modification


Functionalities  -------------------------------------------

1. User Mode

  Registration: Allows new users to register with ID, name, password, and phone number.

  Login: Authenticates existing users based on ID, name, and password.

  View Menu: Displays all available dishes.

  Place Order: Allows users to select dishes and specify quantity to generate a total bill.

2. Admin Mode

  Login: Authenticates admin members with ID, name, and password.

  Add Dish: Allows admins to add new dishes to the menu.

  Remove Dish: Provides an option to remove dishes from the menu.

  View Menu: Displays the current menu.

  View Users and Staff: Lists all registered users and admin staff.

  Add Admin Member: Allows adding new admin members to the system.

Data Handling

  File Handling: All user, admin, and menu data is stored and managed using text files.

  Binary Read/Write: The application uses fwrite() and fread() for efficient data management.

Error Handling

  Displays messages if files cannot be opened.

  Handles invalid choices in menus and login failures.

Future Improvements

  Implement data validation for inputs.

  Enhance menu navigation with better error messages.

  Add data encryption for passwords.

  Implement a graphical user interface (GUI).

Author

Kamlesh Pandit

License

This project is open-source and available for modification and distribution.


