using Plots

function trapez(f, a, b, n)
    if n == 0
        return (b - a) * (f(a) + f(b)) / 2
    else
        m = (a + b) / 2
        left = trapez(f, a, m, n-1)
        right = trapez(f, m, b, n-1)
        return left + right
    end
end

f(x) = 1 / (1+x^2)
(a, b) = (0, 1)
exact = pi / 4

N = 10
error = zeros(Float64, N)
for n = 1:N
    sum = trapez(f, a, b, n)
    error[n] = (sum - exact) / exact
    pc = error[n] * 100
    println("[n=$n] $sum (error: $pc %)")
end

gr()
plot(abs.(error), st=:scatter; yscale=:log10)
png("trapezoid.png")
