# download a chromedriver according to your chrome version here:
# https://googlechromelabs.github.io/chrome-for-testing/#stable
# CHROMEDRIVER_LOCATION = '/usr/bin/chromedriver'
CHROMEDRIVER_LOCATION = '/Users/huangboyi/Downloads/chromedriver-mac-arm64/chromedriver'

# the challenge server has no internet access, so we need to mock the remote resources
# (you can set this to False when testing locally)
MOCK_NETWORK = False

from selenium import webdriver
import time
import threading
import subprocess
from pathlib import Path

import flag_server
import hacker_server

try:
    # print('\nInput your blog HTML below: (end with a separate line of text "EOF")\n')
    # html = ''
    # while True:
    #     line = input('')
    #     if line=='EOF':
    #         break
    #     html += line + '\n'
    # hacker_server.HACKER_HTML = html
    hacker_server.HACKER_HTML = Path(__file__).parent.joinpath('hacker.html').read_text()
    
    print('\nStarting servers...')
    threading.Thread(target=flag_server.start, daemon=True).start()
    threading.Thread(target=hacker_server.start, daemon=True).start()
    if MOCK_NETWORK:
        # subprocess.run('/bin/bash /root/mocked/start_mock.sh', shell=True)
        subprocess.run('/bin/bash ./mocked/start_mock.sh', shell=True)
    time.sleep(1)

    # input('\nPress Enter to start the browser...')
    
    ext_path = (Path(__file__).parent / 'bxx-extension').resolve()
    # ext_path = (Path(__file__).parent / 'taobao-extension-204').resolve()
    assert ext_path.is_dir()

    print(f'\nStarting browser with {ext_path.name}...')
    options = webdriver.ChromeOptions()
    # options.add_argument('--headless') # comment out this line to display the chrome GUI for debugging
    options.add_argument('--no-sandbox') # sandbox not working in docker :(
    options.add_argument(f'--load-extension={ext_path}')
    options.add_experimental_option('excludeSwitches', ['enable-logging'])
    if MOCK_NETWORK:
        options.add_argument('--proxy-server=127.0.0.1:8080')
        options.add_argument('--ignore-certificate-errors')

    with webdriver.Chrome(options=options, service=webdriver.ChromeService(executable_path=CHROMEDRIVER_LOCATION)) as driver:
        # switch to the annoying new tab page opened by the extension
        time.sleep(1)
        driver.switch_to.window(driver.window_handles[0])
        
        print('\nLogging in...')
        # driver.get('http://127.0.1.14:1919/login')
        driver.get('http://127.0.0.1:30000/login')
        time.sleep(1)
        
        print('\nVisiting your blog...')
        # driver.get('http://127.0.5.14:1919/blog')
        driver.get('http://127.0.0.1:31000/blog')
        time.sleep(4)
        
        title = driver.title or '(empty)'
        print('\nThe page title is:', title)

        input('\nPress Enter to close the browser...')

    print('\nSee you later :)')
    
except Exception as e:
    print('ERROR', type(e))
