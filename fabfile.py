from __future__ import with_statement

import os.path

from fabric.api import *
from fabric.contrib.project import *


"""
Environments
"""

def dev():
	env.hosts = ['54.254.133.41']
	env.user = ''
	env.path = '/data/fte_dev'

def staging():
	env.hosts = ['54.254.141.72']
	env.user = ''
	env.path = '/data/fte_dev'

#def prod():
	#env.hosts = ['']
	#env.user = ''
	#env.path = ''

"Default to 'dev' environment"
dev()


"""
Tasks - Deployment
"""

def deploy():
	require('path', provided_by=[dev])

	rsync_project(
		env.path,
		'%s/' % os.path.dirname(__file__),
		['log/*', 'cache/*', '.git', '.htaccess', '.git*', '.DS_Store', 'fabfile.py*', 'sites/default/files/*', 'sites/default/*.php'],
		False
	)

	with cd(env.path):
		run('drush cc all')
		run('drush fra -y')
		run('drush updb')
