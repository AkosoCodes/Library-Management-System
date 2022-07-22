<h1 align="center">Library Management System</h1>

<p>This was a final project assigned for the 'Object Oriented Programming II' course at Singidunum University.</p>

## 📝 | Table of Contents
- [🧐 Project Task <a name="project_task"></a>](#--project-task-)
- [📏 Project Requirements  <a name="requirements"></a>](#--project-requirements--)
- [🏛️ Use Case Diagram <a name="use-case"></a>](#--use-case-diagram-)
- [📚 Class Diagram <a name="class-case"></a>](#--class-diagram-)
- [📸 Demonstration <a name="demo"></a>](#--demonstration-)
- [🧰 Languages & Tools <a name="languages_&_tools"></a>](#--languages--tools-)
- [🏁 Getting Started <a name="getting_started"></a>](#--getting-started-)
- [⚖ License <a name="license"></a>](#--license-)


## 🧐 | Project Task <a name="project_task"></a>

The aim of this project is to build a fully functioning <i><strong>Library Management System</strong></i> from scratch using **C++** and basic **OOP principles**.

<p>A Library Management System should facilitate the library with easy access to their primary functions. These functions include, but are not limited to: maintaining inventory, managing different users, adding and/or removing books, keeping track of borrowed and owed books, etc.</p>


## 📏 | Project Requirements  <a name="requirements"></a>

<p>While designing this project, I will focus on the following set of requirements:</p>
<ol>
    <li>Members should be able to see a list of available books, with their title, author and quantity.</li>
    <li>Each book will contain a unique ID, and other factors for easy targeting.</li>
    <li>There can be many quantities of a single book, so that many members can borrow the same one.</li>
    <li>Librarians will have the option to see a list of all borrowed books, with information of who took them</li>
    <li>Members will be able to borrow books, return them.</li>
    <li>As with books, each member will have their own ID.</li>
    <li>There should be a validation check of credentials when users are logging in.</li>
    <li>Librarians should be able to create and delete current members.</li>
</ol>

## 🏛️ | Use Case Diagram <a name="use-case"></a>

There will be two main actors:
<ul>
    <li>Librarians: Responsible for creating/removing books and members. They will be able to see all the available books, and list of borrowed ones</li>
    <li>Members: Can search catalogue of available books and borrow books</li>
</ul>

The main use-cases for this project are:
<ul>
    <li>Manage Books</li>
    <li>Manage Members</li>
    <li>Search Books</li>
    <li>Borrow/Return Books</li>
    <li>Login</li>
</ul>

{WIP: Add Use Case Diagram here}

## 📚 | Class Diagram <a name="class-case"></a>

<p>The main classes used for this project are:</p>
<ul>
<li><strong>Library</strong>: As this is a Library Management System designed for a chain of libraries, each one will have its own ID and address to be distinguished.</li>
    <ul><li>It will contain a getAddress() function to retrieve the ID and Address of the library.</li></ul><br>
<li><strong>Book</strong>: The primary part of this system. It will contain a title, author and the format. It will also have a unique ID. </li>
    <ul><li>It will contain a bookInfo() function to retrieve information about the book.</li></ul><br>
<li><strong>Book Item (extends Book)</strong>: As there can be multiple copies for a single book, it should be differentiated into an item. It will contain the quantity, status, due date, and borrow date. </li><br>
<li><strong>Account</strong>: There will be two different types of accounts, Members and Librarians. Both will contain ID, username, password, status and personal information.</li>
<ul><li>Librarians (extends Account): will have the functions to add/deleteBook(), block/unblockMember().</li></ul>
<ul><li>Members (extends Account): will have additional attributes of totalBorrowed().</li></ul><br>
<li><strong>Book Reservation</strong>: will store information about the lending of the books.</li><br>
</ul>

{WIP: Add Class Diagram here}

## 📸 | Demonstration <a name="demo"></a>

{WIP: GIFS and Images here}


## 🧰 | Languages & Tools <a name="languages_&_tools"></a>
<p><img src="https://img.icons8.com/color/344/c-plus-plus-logo.png" width=30 alt="C++">
<a href="https://www.jetbrains.com/clion/"><img src="https://static.cdnlogo.com/logos/c/21/clion.svg" width=30 alt="C-Lion"></a></p>

## 🏁 | Getting Started <a name="getting_started"></a>
These instructions will get you a copy of the project up and running on your local machine.

**<h3>Requirements:</h3>**
<ul>
<li>C++ Compiler</li>
</ul>

**<h3>Guide:</h3>**
<ol>
<li>Compile the file</li>
<li>Run the output</li>
<li>Have fun! :)</li>
</ol>

## ⚖ | License <a name="license"></a>
This repository is not under any license. Normal copyright laws apply.
