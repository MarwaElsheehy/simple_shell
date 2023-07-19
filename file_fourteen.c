#include "shell.h"

/**
 * _outlet- outlet the husk
 * @i: argument include temple used to preserve of  mission  model
 *  Return: if success 0 otherwise 1
 */
int _outlet(info_t *i)
{
	int k;

	if (i->argv[1]) 
	{
		k = _resolve(i->argv[1]);
		if (k == -1)
		{
			i->status = 2;
			press_false(i, "Illegal number: ");
			_place(i->argv[1]);
			_design('\n');
			return (1);
		}
		i->err_num = _resolve(i->argv[1]);
		return (-2);
	}
	i->err_num = -1;
	return (-2);
}

/**
 * _compress - variation of the influx dir of the stream
 * @j: argument include temple used to preserve of  mission  model
 *  Return: if success 0 otherwise 1
 */
int _compress(info_t *j)
{
	char *c, *d, b[1024];
	int a;

	c = getcwd(b, 1024);
	if (!c)
		_lay("TODO: >>getcwd failure emsg here<<\n");
	if (!j->argv[1])
	{
		d = _takethough(j, "HOME=");
		if (!d)
			a = chdir((d = _takethough(j, "PWD=")) ? d : "/");
		else
			a = chdir(d);
	}
	else if (_combine(j->argv[1], "-") == 0)
	{
		if (!_takethough(j, "OLDPWD="))
		{
			_lay(c);
			_force('\n');
			return (1);
		}
		_lay(_takethough(j, "OLDPWD=")), _force('\n');
		a = chdir((d = _takethough(j, "OLDPWD=")) ? d : "/");
	}
	else
		a = chdir(j->argv[1]);
	if (a == -1)
	{
		press_false(j, "can't cd to ");
		_place(j->argv[1]), _design('\n');
	}
	else
	{
		_suitthough(j, "OLDPWD", _takethough(j, "PWD="));
		_suitthough(j, "PWD", getcwd(b, 1024));
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

