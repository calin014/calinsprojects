#!/usr/bin/env python
#
# Copyright 2007 Google Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#	 http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
from google.appengine.ext import webapp
from google.appengine.ext.webapp import util

from controller.main_handler import MainHandler
from controller.transaction_handler import TransactionHandler
from controller.category_handler import CategoryHandler
from controller.upload_handler import UploadHandler

def main():
	application = webapp.WSGIApplication(
		[
			('/', MainHandler),
			('/transaction', TransactionHandler),
			('/category', CategoryHandler),
			('/upload', UploadHandler)
		], debug=True)
	util.run_wsgi_app(application)

if __name__ == '__main__':
	main()