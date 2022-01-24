import { NgModule } from "@angular/core";
import { RouterModule, Routes } from "@angular/router";
import { GradesComponent } from "./dyna/grades/grades.component";
import { HomeComponent } from "./dyna/home/home.component";
import { NotfoundComponent } from "./dyna/notfound/notfound.component";
import { RedieComponent } from "./dyna/redie/redie.component";

const routes: Routes = [
  {
    path: "",
    redirectTo: "home",
    pathMatch: "full",
  },
  {
    path: "home",
    component: HomeComponent,
  },
  {
    path: "grades",
    component: GradesComponent,
  },
  {
    path: "redie",
    component: RedieComponent,
  },
  {
    path: "**",
    component: NotfoundComponent,
  },
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule],
})
export class AppRoutingModule {}
