//
// Member.cpp
//
 
#include "Member.h"
 
/* Member default constructor
* Postcondition: username, name, datebirth, email and phonenumber are empty strings, year == 0.
*            
*/
Member::Member() {
    username = "";
    name = "";
    datebirth = "";
    email = "";
    phonenumber = "";
    year = 0;
}
/* Explicit constructor
    * @param: username, a string
    * @param: name, a string
    * @param: datebirth, a string
    * @param: email, a string
    * @param: phonenumber, a string.
    * @param: year, an unsigned int.
    * Postcondition: this -> username == username &&
    *                this -> name == name &&
    *                this -> datebirth == datebirth &&
    *                this -> email == email &&
    *                this -> phonenumber == phonenumber &&
    *                this -> year == year.
 
    */
Member::Member(const string& username, const string& name, const string& datebirth, const string& email, const string& phonenumber, unsigned year) {
    this -> username = username;
    this -> name = name;
    this -> datebirth = datebirth;
    this -> email = email;
    this -> phonenumber = phonenumber;
    this -> year = year;
 
}
 
/* getter method for username
 * Return: username
 */
string Member::getUsername() {
    return username;
}
 
/* getter method for name
 * Return: name
 */
string Member::getName() {
    return name;
}
 
/* getter method for DateBirth
 * Return: DateBirth
 */
string Member::getDateBirth() {
    return datebirth;
}
 
/* getter method for email
 * Return: email
 */
string Member::getEmail() {
    return email;
}
 
/* getter method for phonenumber
 * Return: phonenumber
 */
string Member::getPhoneNumber() {
    return phonenumber;
}
 
/* getter method for registered year 
* Return: year
*/ 
unsigned Member::getYear() {
    return year; 
}

/* Member input method...
 * @param: in, an istream
 * Precondition: in contains the username, name, datebirth, email, phonenumber and registered year data for a Member.
 * Postcondition: the username, name, datebirth, email, phonenumber and registered year data have been read from in &&
 *                this -> username == username &&
 *                this -> name == name &&
 *                this -> datebirth == datebirth &&
 *                this -> email == email &&
 *                this -> phonenumber == phonenumber &&
 *                this -> year == year.
 */
void Member::readFrom(istream& in) {
    getline(in, this -> username);
    getline(in, this -> name);
    getline(in, this -> datebirth);
    getline(in, this -> email);
    getline(in, this -> phonenumber);
    string yearString;
    getline(in, yearString);
    this -> year = atoi( yearString.c_str());
} 

/* Member output...
 * @param: out, an ostream
 * Postcondition: out contains username, a newline,
 *                             name, a newline,
 *                             datebirth, a newline,
 *                             email, a newline,
 *                             phonenumber, a newline,
 *                             year, a newline.
 *
 */
void Member::writeTo(ostream& out) const {
    out << this -> username << '\n'
    << this -> name << '\n'
    << this -> datebirth << '\n'
    << this -> email << '\n'
    << this -> phonenumber  << '\n'
    << this -> year  << '\n';
}
