using Plots
using LaTeXStrings

function index(x, q)
	p = round(x * q)
	-log(q, abs(p/q-x))
end

idxplot = plot(
	title="Rational approximants of pi",
	xlabel=L"q",
	ylabel=L"-\log_q |p/q-\pi|",
	fmt=:png
)
nmax = 1000

fs = [index(pi, n) for n in 1:nmax]

scatter!(idxplot,
	1:nmax,
	fs,
	minorgrid=true,
	markersize=2,
	legend=false
)

savefig(idxplot, "pi.png")

