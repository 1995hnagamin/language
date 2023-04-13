using Plots

f(x) = tan(x) / x

plot(x -> abs(f(1im*x)),
	ribbon=(x -> (x/400)^4),
	xlim=(1e-1,1e2),
	ylim=(5e-3,1.1),
	xaxis=:log,
	yaxis=:log)
