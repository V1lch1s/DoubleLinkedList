# DoubleLinkedList
Double linked list data structure which can easily replace the C++ vector library XD.

Please save me trouble and support my project by citing my code, thanks.

Functions (DoubleLinkedList):
insertAt() ~Inserts an element at the given index by the user
removeAt() ~Deletes an element at the given index by the user
getSize() ~This gets the size (number of nodes) of the data structure
pushFront() ~Creates an element at the beginning of the data structure
pushBack() ~Creates an element at the end of the data structure
getNode() ~This gets the current node --- myVector.getNode(integer_position)
print() ~This prints the whole array
How to modify the node data:

// Declaras un nodo utilizando la clase inscrita en DoubleLinkedList
Nodo<string>* node = incidents.getNode(i); // Returns de whole node

// Apuntas a la variable miembro "data" 
string myNodeData = node->data; // Returns the node's data

// Actualiza el nodo en la lista enlazada con la información modificada si es necesario.
node->data = incidentData;
