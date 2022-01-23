import { ComponentFixture, TestBed } from "@angular/core/testing";

import { BasepageComponent } from "./basepage.component";

describe("BasepageComponent", () => {
  let component: BasepageComponent;
  let fixture: ComponentFixture<BasepageComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [BasepageComponent],
    }).compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(BasepageComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it("should create", () => {
    expect(component).toBeTruthy();
  });
});
