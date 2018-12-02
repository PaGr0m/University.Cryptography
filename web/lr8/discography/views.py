from django.shortcuts import render
from django.shortcuts import get_object_or_404
from django.views.generic import View
from django.contrib.auth.mixins import LoginRequiredMixin

from .models import Musician, Song
from .utils import ObjectCreateMixin, ObjectReadMixin, ObjectUpdateMixin, ObjectDeleteMixin
from .forms import MusicianForm, SongForm


def mus_list(request):
    musicians = Musician.objects.all()
    context = {
        "musicians": musicians
    }
    return render(request=request,
                  template_name="discography/musician_main.html",
                  context=context)


class MusicianCreate(LoginRequiredMixin, ObjectCreateMixin, View):
    model_form = MusicianForm
    template = "discography/musician_create.html"
    raise_exception = True


class MusicianRead(ObjectReadMixin, View):
    model = Musician
    template = "discography/musician_read.html"


class MusicianUpdate(LoginRequiredMixin, ObjectUpdateMixin, View):
    model = Musician
    model_form = MusicianForm
    template = "discography/musician_update.html"
    raise_exception = True


class MusicianDelete(LoginRequiredMixin, ObjectDeleteMixin, View):
    model = Musician
    template = "discography/musician_delete.html"
    redirect_url = "musician_list_url"
    raise_exception = True


class SongCreate(LoginRequiredMixin, ObjectCreateMixin, View):
    model_form = SongForm
    template = "discography/song_create.html"
    raise_exception = True


class SongRead(ObjectReadMixin, View):
    model = Song
    template = "discography/song_read.html"


class SongUpdate(LoginRequiredMixin, ObjectUpdateMixin, View):
    model = Song
    model_form = SongForm
    template = "discography/song_update.html"
    raise_exception = True


class SongDelete(LoginRequiredMixin, ObjectDeleteMixin, View):
    model = Song
    template = "discography/song_delete.html"
    redirect_url = "song_list_url"
    raise_exception = True


def song_list(request):
    songs = Song.objects.all()
    context = {
        "songs": songs
    }
    return render(request=request,
                  template_name="discography/song_main.html",
                  context=context)
