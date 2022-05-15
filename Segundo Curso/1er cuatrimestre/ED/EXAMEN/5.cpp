vector<list<int>> secuenciascaminos (bintree<int> A, int nivel){
    vector<list<int>> salida;
    list<int> mejor;
    bintree<int>::node n = A.root();
    int level = 0;

    while(/*No se la condicion de salida*/){
        if(!n.left().null() && level == nivel){
            mejor.push_back(*n);
            n=n.left();
        }
        else if(!n.right().null() && level == nivel){
            mejor.push_back(*n)
            n=n.right();
        }

        level++;

        if(n.null()){
            if(mejor.size() > 1){
                salida.push_back(mejor);
            }
            else{
                mejor.clear();
                bintree<int>::node n = A.root();
            }
        }

        if()
        
    }

    return salida;

}