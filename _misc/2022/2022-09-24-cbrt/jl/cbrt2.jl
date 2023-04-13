using Plots
using LaTeXStrings

function index(x, q)
	p = round(x * q)
	-log(q, abs(p/q-x))
end

idxplot = plot(
	title="Rational approximants of cubic root of 2",
	xlabel=L"q",
	ylabel=L"-\log_q |p/q-\sqrt[3]{2}|",
	fmt=:png
)
nmax = 1000

fs = [index(cbrt(2), n) for n in 1:nmax]

scatter!(idxplot,
	1:nmax,
	fs,
	minorgrid=true,
	markersize=2,
	legend=false
)

savefig(idxplot, "cbrt2.png")

