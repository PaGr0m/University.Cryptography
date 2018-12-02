from django.http import HttpResponse
from django.shortcuts import redirect


def redirect_url(request):
    return redirect("musician_list_url", permanent=True)
