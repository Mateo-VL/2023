from pylab import *
from scipy.interpolate import lagrange
from scipy.interpolate import interp1d
from scipy.interpolate import CubicSpline


def g(x): return (((9 * x - 2)**2)/4)
def h(x): return (((9 * x + 1)**2)/49)
def j(x): return (((9 * x + 1)**2)/10)
def k(x): return (((9 * x - 7)**2)/4)
def l(x): return (((9 * x - 3)**2)/4)


def f(x1, x2): return (0.75 * exp((-1 * g(x1)) - g(x2)) +
                       0.75 * exp((-1*h(x1))-h(x2)) + 0.5 * exp((-1 * k(x1))-l(x2)) - 0.2 * exp((-1 * k(x1))-l(x2)))


a = np.linspace(-1, 1, num=10)
xp = np.array(a)


poly = interp1d(xp, f(xp), kind='linear')
poly2 = CubicSpline(xp, f(xp))
poly3 = lagrange(xp, f(xp))

x = np.linspace(-1, 1, num=200)
plot(x, f(x), label='f')
plot(xp, f(xp), 'bo')
plot(x, poly3(x), label='interp', ls='--')

legend()
err_max = np.max(np.abs(f(x)-poly3(x)))

print(err_max)

show()
