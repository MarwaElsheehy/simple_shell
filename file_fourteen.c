#include "shell.h"

/**
 * _outlet- outlet the husk
 * @I: argument include temple used to preserve of  mission  model
 *  Return: if success 0 otherwise 1
 */
int _outlet(info_t *I)
{
	int k;

	if (I->argv[1]) 
	{
		k = _resolve(I->argv[1]);
		if (k == -1)
		{
			I->status = 2;
			press_false(I, "Illegal number: ");
			_place(I->argv[1]);
			_design('\n');
			return (1);
		}
		I->err_num = _resolve(I->argv[1]);
		return (-2);
	}
	I->err_num = -1;
	return (-2);
}

/**
 * _compress - variation of the influx dir of the stream
 * @Q: argument include temple used to preserve of  mission  model
 *  Return: if success 0 otherwise 1
 */
int _compress(info_t *Q)
{
	char *c, *d, b[1024];
	int a;

	c = getcwd(b, 1024);
	if (!c)
		_lay("TODO: >>getcwd failure emsg here<<\n");
	if (!Q->argv[1])
	{
		d = _takethough(Q, "HOME=");
		if (!d)
			a = chdir((d = _takethough(Q, "PWD=")) ? d : "/");
		else
			a = chdir(d);
	}
	else if (_combine(Q->argv[1], "-") == 0)
	{
		if (!_takethough(Q, "OLDPWD="))
		{
			_lay(c);
			_force('\n');
			return (1);
		}
		_lay(_takethough(Q, "OLDPWD=")), _force('\n');
		a = chdir((d = _takethough(Q, "OLDPWD=")) ? d : "/");
	}
	else
		a = chdir(Q->argv[1]);
	if (a == -1)
	{
		press_false(Q, "can't cd to ");
		_place(Q->argv[1]), _design('\n');
	}
	else
	{
		_suitthough(Q, "OLDPWD", _takethough(Q, "PWD="));
		_suitthough(Q, "PWD", getcwd(b, 1024));
	}
	return (0);
}

/**
 * _assist - variation of the influx dir of the stream
 * @v: argument include temple used to preserve of  mission  model
 *  Return: if success 0 otherwise 1
 */
int _assist(info_t *v)
{
	char **w;

	w = v->argv;
	_lay("help call works. Function not yet implemented \n");
	if (0)
		_lay(*w); 
	return (0);
}

