#Implement an SLL in Python (HW7-1&2.py) with add and remove to the back and front methods. (10 points)

class Node:

    def __init__(self,data):
        self.data = data
        self.next = None

class LinkedList:

    def __init__(self):
        self.next = None

    def printList(self):
        temp = self.head
        while(temp):
            print temp.data,
            temp = temp.next
        print ''

    def addBack(self,var_add):
        temp = Node(var_add)
        temp.next=None
        if(self.head == None):
            self.head = temp
        else:
            ptr = self.head
            while(ptr.next!=None):
                ptr = ptr.next
            ptr.next = temp

    def addFront(self,var_add):
        temp = Node(var_add)
        temp.next = self.head
        self.head = temp

    def removeBack(self):
        if(self.head == None):
             print 'the linked list is empty'
        elif(self.head.next==None):
            #only one item
            self.head = None

        else:
            temp = self.head
            while(temp.next.next!=None):
                temp = temp.next
            temp.next= None


    def removeFront(self):
        if (self.head == None):
            print 'the linked list is empty'
        elif (self.head.next is None):
            # only one item
            self.head = None
        else:
            temp = self.head
            self.head = temp.next

    def reversed(self):
        #if empty
        if (self.head == None or self.head.next==None):
            return
        #swap the 1st and 2nd

        pre = self.head
        after = self.head.next

        pre.next = after.next
        after.next = pre
        self.head = after

        while(pre.next!=None):
            #make the point to the right position
            temp = pre#temp is after
            pre = after
            after = temp
            # print pre.data
            # print after.data
            if(after.next.next!=None):
                #move after two step
                pre=pre.next.next
                after = after.next.next

                pre.next = after.next
                after.next = pre
                temp.next = after
            else:
                return
















# Code execution starts here
if __name__ == '__main__':
    # Start with the empty list
    llist = LinkedList()

    llist.head = Node(1)
    llist.addBack(3)
    llist.addBack(4)
    llist.addBack(6)
    llist.addBack(7)
    llist.addBack(11)
    llist.addBack(7)

    llist.printList()
    llist.reversed()
    llist.printList()


    # Link second node with the third node

    print "\n"
