fn id<T>(x: T) -> T {
    return x;
}

fn comp<F, G, A, B, C>(f: F, g: G) -> impl Fn(A) -> C
where
    F: Fn(A) -> B,
    G: Fn(B) -> C,
    // H: Fn(A) -> C. This doesn't work for a variety of reasons.
{
    // move f and g into the scope of the close as immutable references
    return move |x| g(f(x));
}

fn i2b(x: u32) -> bool {
    if x != 0 {
        true
    } else {
        false
    }
}

fn main() {
    println!("Hello, world!");
    let x: u32 = 2;
    let y = id(x);
    println!("x {}, y {}", x, y);
    let f2 = comp(i2b, id::<bool>);
    let x1 = i2b(3);
    let x2 = f2(3);
    println!("f1 {}, f2 {}", x1, x2);
}
