from pylab import *
from scipy.interpolate import lagrange
from scipy.interpolate import interp1d
from scipy.interpolate import CubicSpline


def f(x): return (-0.4 * tanh(50 * x) - 0.6)


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
