from django.urls import path
from .views import MusicianCreate, MusicianRead, MusicianUpdate, MusicianDelete
from .views import SongCreate, SongRead, SongUpdate, SongDelete
from .views import mus_list, song_list


urlpatterns = [
    path("musician/", mus_list, name="musician_list_url"),
    path("musician/create/", MusicianCreate.as_view(), name="musician_create_url"),
    path("musician/<str:slug>/", MusicianRead.as_view(), name="musician_read_url"),
    path("musician/<str:slug>/update/", MusicianUpdate.as_view(), name="musician_update_url"),
    path("musician/<str:slug>/delete/", MusicianDelete.as_view(), name="musician_delete_url"),

    path("song/", song_list, name="song_list_url"),
    path("song/create/", SongCreate.as_view(), name="song_create_url"),
    path("song/<str:slug>/", SongRead.as_view(), name="song_read_url"),
    path("song/<str:slug>/update/", SongUpdate.as_view(), name="song_update_url"),
    path("song/<str:slug>/delete/", SongDelete.as_view(), name="song_delete_url"),

]
