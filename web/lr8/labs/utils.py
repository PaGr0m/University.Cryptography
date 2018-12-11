from django.shortcuts import redirect, render, reverse


class ObjectCreateMixin:
    model_form = None
    template = None

    def get(self, request):
        form = self.model_form
        context = {
            "form": form
        }

        return render(request=request,
                      template_name=self.template,
                      context=context)

    def post(self, request):
        bound_form = self.model_form(request.POST)
        context = {
            "form": bound_form
        }

        if bound_form.is_valid():
            new_obj = bound_form.save()

        return render(request=request,
                      template_name=self.template,
                      context=context)
