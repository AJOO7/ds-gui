# ds-gui
<embed>https://github.com/AJOO7/ds-gui/blob/main/DataStrPro/ds-gui.pdf</embed>
### THE RESTURANT

### MANAGEMENT SYSTEM


#### INTRODUCTION

##### ⦿ As the name suggests that its is for ordering foods at a food

```
house and updating of the menu ,discount price by the owner and
generates bills of food ordered
```
##### ⦿ It save time and decreases the work of the owner and waiter too

```
It will also help the owners to handle their customers in a better
and a comfortable way
```

#### AIM

##### ⦿ As we know how much COVID 19 have affected us all and even more the

```
small food chain as they don’t have much capital so we have designed
this restaurant billing management system to help them recover faster in
the race
```
##### ⦿ The RESTURANT BILLING MANAGEMENT SYSTEM is a basic program

```
which can be used in small restaurants and food chains so decreasing as
much as direct human contact is possible
```

## FLOW OF

## CODE


#### ORDER FOOD


#### ADMIN


## CODE

## EXPLANATION

# #


#### MENU CLASS

##### ⦿ For Insertion:-We first create a new node having name of the dish and

```
their price. When the menu is empty, we updated both head and tail
with the new node.
```
##### ⦿ After that for insertion we use tail node. We make the next node of tail

```
as the new inserted node and update the tail to the new node, in this
way we can perform the insertion in the time complexity of O(1).
```

#### MENU CLASS

##### ⦿ For Deletion:-We first check whether the linked list is empty or not. If it

```
is not empty then we traverse the list. If the required deleted dish is not
in the list then we show an output ”Dish not found the menu”, and if the
dish is found in the list then we simply delete it.
```
##### ⦿ For show menu:-We first ask the customer about their choice i.e.

```
veg,non-veg,Chinesethen we traverse the required list and display the
name of the dish with their prices.
```

#### CUSTOMER CLASS

##### ⦿ For Insertion:-We allocate a customer id to each of our first time customer.

```
The customer node consists of an id and no. of visits of the customer to
our hotel. In this also we have two nodes start and End so that the
insertion of the customer can be performed in O(1) time complexity.
```
##### ⦿ For increasing no. of visits:-Upon the arrival of the customer we ask for

```
their customer id if they have already visited our hotel earlier, then we
traverse the customer list and update their no. of visits by 1. If the id given
by customer is not found in our record then we display a message
“No such id is found”. 10
```

#### CUSTOMER CLASS

##### ⦿ For discount:-We also give discount to our regular customer according

```
to their no. of visits. For visits greater than 20 we gave a discount of 25%
and for visits greater than 10 we gave a discount of 15%.
```

## DATABASE

# #


##### ⦿ Files was used to store data in a storage device

###### permanently.

##### ⦿ File handling provides a mechanism to store the output of a

###### program in a file and to perform various operations on it.

##### ⦿ We have used files as a database to store the food items in the

```
menu and order list and the customer id and last id for all the
function in the program
```

#### FILES

##### ⦿ Veg.txt:-it store the information of all the veg dishes that are inserted by

```
the owner and can be ordered by the customer.Thefile store the data in
the format of first line as name and second as the price.
```
##### ⦿ nonVeg.txt:-it store the information of all the nonVegdishesthat are

```
inserted by the owner and can be ordered by the customer.Thefile store
the data in the format of first line as name and second as the price
```

#### FILES

##### ⦿ Chinese.txt:-it store the information of all the Chinese dishes that are

```
inserted by the owner and can be ordered by the customer.Thefile store
the data in the format of first line as name and second as the price
```
##### ⦿ Customer.txt:-it conatinsthe id of the customers and the no fovisits


## GUI

# #


```
ORDER BUTTON
TO GO TO THE
MENU PAGE
```
```
ADIM BUTTON TO
GO TO ADMIN
AUTHENTICATION
PAGE
```
#### MAIN WINDOW


```
GO BACK TO
PARENT PAGE
```
```
ADD A NEW
CUSTOMER IN THE
DATABASE AND
GO TO MENU
```
LOGIN VIA THE
PREVIOUS ID
AND GO TO THE
MENU

#### CUSTOMER LOGIN PAGE


```
DIRECTS TO THE
VEG MENU PAGE
```
```
DIRECTS TO THE
NON VEG MENU
PAGE
```
```
DIRECTS TO THE
CHINESE MENU
PAGE
```
```
DIRECTS BACK
TO THE PARENT
PAGE
```
#### MAIN MENU PAGE


```
THE FORM LAYOUT
CANTAINS ALL THE
INFO OF THE FOOD
AVAILABLE AND
HAVE COMBO BOX
TO SET THE
QUANTITY TO
SELECT BY THE
CUSTOMER
```
```
ALL THE SELECTED
ITEM AND TOTAL IS
PASSED TO THE
NEXT PAGE
```
DIRECTS TO THE
PARENT PAGE

#### VEG MENU PAGE


```
THE TOTAL PRICE
AND THE LIST OF
ALL THE ITEMS
SELECTED IS
PASSED HERE BY
THE PARENT
PAGE
```
```
CONFIRM BUTTON
CONFIRM THE
ORDER AND
DIRECTS TO THE
PAYMENT PAGE
```
#### ORDER CONFIRMATION PAGE


```
THE TOTAL IS
PASSED BY
THE PARENT
PAGE
```
```
PAYMENT
OPTIONS
*(DISABLED)
```
```
CLOSE THE
APPLICATION
```
#### PAYMENT PAGE


```
SUBMIT THE USER
ID AND PASSWORD
AND CHECK THEIR
AUTHENTICATION
IN THE DATABASE
AND IF TRUE THEN
DIRECTS TO THE
ADMIN PAGE
```
```
DIRECTS TO
THE PARENT
PAGE
```
LINE EDIT TO
READ USER ID
FROM THE
USER

```
LINE EDIT TO
READ
PASSWORD
FROM THE
USER
```
#### LOGIN PAGE


```
DIERECTS TO
THE SPECIFIC
PAGE WHERE
THE DISHES IN
THE MENU CAN
BE UPDATED
```
```
DIRECTS TO
THE PARENT
PAGE
```
#### ADMIN WINDOW


```
LINE EDIT
FOR THE
PRICE OF THE
NEW DISH
```
LINE EDIT FOR
THE NAME OF
THE NEW DISH

```
LINE EDIT FOR
DELETING A
DISH FROM
THE MENU DIRECTS TO
THE PARENT
PAGE
```
#### UPDATE PAGE


## THANKS

# #



