import os
import urllib.request
from tqdm import tqdm
import zipfile

def download_with_progress(url, filename):
    class DownloadProgressBar(tqdm):
        def update_to(self, b=1, bsize=1, tsize=None):
            if tsize is not None:
                self.total = tsize
            self.update(b * bsize - self.n)

    print(f"Downloading {filename}...")
    with DownloadProgressBar(unit='B', unit_scale=True, miniters=1, desc=filename) as t:
        urllib.request.urlretrieve(url, filename, reporthook=t.update_to)

# Create directory if it doesn't exist
os.makedirs('evaluation/bleurt/bleurt_repo', exist_ok=True)
os.chdir('evaluation/bleurt/bleurt_repo')

# Download BLEURT-20
url = "https://storage.googleapis.com/bleurt-oss-21/BLEURT-20.zip"
filename = "BLEURT-20.zip"

try:
    download_with_progress(url, filename)
    print("\nExtracting BLEURT-20 checkpoint...")
    with zipfile.ZipFile(filename, 'r') as zip_ref:
        zip_ref.extractall("BLEURT-20")
    print("BLEURT-20 setup complete!")
except KeyboardInterrupt:
    print("\nDownload interrupted. Cleaning up...")
    if os.path.exists(filename):
        os.remove(filename)
    print("Cleanup complete.")
except Exception as e:
    print(f"\nError occurred: {str(e)}")
    if os.path.exists(filename):
        os.remove(filename)
    print("Cleanup complete.") 