#include <cstdio>
#include <functional>
// q1
template <typename T>
T id(T x){
    return x;
}
// q2
template <typename A, typename B, typename C>
// = (implicitly capture the used variables with automatic storage duration by copy). 
std::function<C(A)> comp(std::function<B(A)> f, std::function<C(B)>g){
            // = means "hey! copy f and g from the parent scope into this lambda"
    return [=](B x) {return g(f(x));};

}

// let f for example be a cast to bool

bool f(int x){
    if (x != 0) {
        return true;
    }
    else {
        return false;
    }
}




int main(){
    int x = 2;
    int y = id<int>(x);
    // q3
    std::function<bool(int)>f2 = comp<bool, int, bool>(f, id<int>);
    printf("x %d y %d\n", x, y);
    printf("f(3) is %d\n", f(3));
    printf("f2(3) is %d\n", f2(3));


    return 0;
}


// i guess you can think of the www and facebook as categories as long as you have "links" to yourself
// a digraph is a category when a node has an arrow to itself