use std::time::Instant;

fn tarai(x: i32, y: i32, z: i32) -> i32 {
    if x > y {
        tarai(tarai(x-1, y, z), tarai(y-1, z, x), tarai(z-1, x, y))
    } else {
        y
    }
}

fn measure(x: i32, y: i32, z: i32, ntimes: i32) -> Vec<f64> {
    let mut result = Vec::new();
    for _ in 1..ntimes {
        let instant = Instant::now();
        let v = tarai(x, y, z);
        let end = instant.elapsed();
        let time = end.as_secs() as f64
            + end.subsec_nanos() as f64 / 1_000_000_000.0;
        println!("{} ({})", time, v);
        result.push(time);
    }
    result
}

fn average(xs: &[f64]) -> f64 {
    let sum: f64 = Iterator::sum(xs.iter());
    sum / (xs.len() as f64)
}

fn main() {
    let params = [
        (10, 5),
        (11, 5),
        (12, 6),
        (13, 6),
        (13, 7),
        (14, 7),
    ];
    for (x, y) in params {
        println!("x = {}, y = {}", x, y);
        let result = measure(x, y, 0, 10);
        println!("average: {} sec\n", average(&result));
    }
}
