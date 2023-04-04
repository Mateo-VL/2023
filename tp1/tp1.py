from pylab import *
from scipy.interpolate import lagrange
from scipy.interpolate import CubicSpline

h = 0.2
xp = np.arange(0, 1, h)
print(xp)
points = np.exp(xp)
poli_inter = lagrange(xp, points)

x = np.linspace(0, 1, num=200)
plot(x, np.exp(x), label='$f$')
plot(x, poli_inter(x), label='Interp')
plot(xp, np.exp(xp), 'bo')
legend()
show()


def f(x): return 1/x


xp = np.array([2, 2.75, 4])
poly = lagrange(xp, f(xp))

x = np.linspace(2, 4)
plot(x, f(x), label='f')
plot(xp, f(xp), 'bo')
plot(x, poly(x), label='interp', ls='--')
legend()

err_max = np.max(np.abs(f(x)-poly(x)))
print(err_max)

show()
