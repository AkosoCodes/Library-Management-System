 <h1>Library Management System</h1>
<p>Andrija Stanković - 202030164</p>

<h2>Introduction</h2>

<p>The aim of this project is to build a fully functioning <i><strong>Library Management System</strong></i> from scratch using <strong>C++</strong> and basic <strong>OOP principles</strong>.</p>
<p>A Library Management System should facilitate the library with easy access to their primary functions. These functions include, but are not limited to: maintaining inventory, managing different users, adding and/or removing books, keeping track of borrowed and owed books, etc.</p>

<h2>System Requirements</h2>
<p>While designing this project, I will focus on the following set of requirements:</p>
<ol>
    <li>Members should be able to see a list of available books, with their title, author and quantity.</li>
    <li>Each book will contain a unique ID, and other factors for easy targeting.</li>
    <li>There can be many quantities of a single book, so that many members can borrow the same one.</li>
    <li>Librarians will have the option to see a list of all borrowed books, with information of who took them, as well as the due date.</li>
    <li>Members will be able to borrow books, return them.</li>
    <li>As with books, each member will have their own ID.</li>
    <li>There should be a validation check of credentials when users are logging in.</li>
    <li>Librarians should be able to create and delete current members.</li>

</ol>

<h2>Use Case Diagram</h2>

<p>There will be two main actors:</p>
<ul>
    <li>Librarians: Responsible for creating/removing books and members. They will be able to see all the available books, list of borrowed ones, and due dates.</li>
    <li>Members: Can search catalogue of available books, borrow books and check their own due dates.</li>
</ul>
<p>The main use-cases for this project are:</p>
<ul>
    <li><strong>Manage Books</strong></li>
    <li><strong>Manage Members</strong></li>
    <li><strong>Search Books</strong></li>
    <li><strong>Borrow/Return Books</strong></li>
    <li><strong>Login</strong></li>
    <li><strong>Check Deadlines</strong></li>
</ul>

<h2>Class Diagram</h2>
<p>The main classes used for this project are:</p>
<ul>
<li><strong>Library</strong>: As this is a Library Management System designed for a chain of libraries, each one will have its own ID and address to be distinguished.</li>
    <ul><li>It will contain a getAddress() function to retrieve the ID and Address of the library.</li></ul>
<li><strong>Book</strong>: The primary part of this system. It will contain a title, author and the format. It will also have a unique ID. </li>
    <ul><li>It will contain a bookInfo() function to retrieve information about the book.</li></ul>
<li><strong>Book Item (extends Book)</strong>: As there can be multiple copies for a single book, it should be differentiated into an item. It will contain the quantity, status, due date, and borrow date. </li>
<li><strong>Account</strong>: There will be two different types of accounts, Members and Librarians. Both will contain ID, username, password, status and personal information.</li>
<ul><li>Librarians (extends Account): will have the functions to add/deleteBook(), block/unblockMember().</li></ul>
<ul><li>Members (extends Account): will have additional attributes of totalBorrowed(), and membershipDate().</li></ul>
<li><strong>Book Reservation</strong>: will store information about the lending of the books. It will contain the creation date, and due date.</li>
<li><strong>Search/Inventory</strong>: contains list of all books which can be sorted in different ways (such as by title, Author, A-Z, Z-A, etc...)</li>





</ul>
